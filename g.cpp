#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define R real
#define I imag
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

double prob[510];
double logfac[510];
double ans[510];

void init()
{
	logfac[0] = 0;
	forsn(i,1,510)
	{
		logfac[i] = logfac[i-1] + log(i);
		//if(i < 20) cout << exp(logfac[i]) << " ";		
	}
}

double logpr(int n, int k, int j)
{
	double ans = log(k * (k - 1)) + logfac[n-2-j] + logfac[n-k] - logfac[n] -  logfac[n - j - k];
	
	return (ans);
}

double pr(int n, int k, int j)
{
	double ans = exp(logpr(n,k,j));

	return (ans);
}

int main()
{
	int n,k;

	cin >> n >> k;

	cout.setf(ios::fixed | ios::showpoint);
   	cout.precision(10);

	forn(i,n) cin >> prob[i];

	init();

	if(k == 1)
	{
		forn(i,n)
		{
			ans[i] = 100.0/(n + .0);
		}

	}
	else
	{
		forn(i,n)
		{
			ans[i] = 0;
			double acum = prob[i];
			//int index = i;
			forn(j,n-k+1)
			{
				//cout << pr(n,k,j) << " " << acum << endl;
				ans[i] += pr(n,k,j) * acum;

				int index = (i - j - 1);
				if(index < 0) index += n;
				acum += prob[index];
			}
		}
	}
	forn(i,n-1) cout << ans[i] << " ";
	cout << ans[n-1] << endl;
	
	return 0;
}