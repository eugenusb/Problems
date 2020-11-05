#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

double pr[10205][110];

double doesItMatter(int N, int G)
{
	pr[5000][0] = 1.0;
	
	forsn(j,1,N+1)
	{
		forsn(d,110,10000)
		{				
			pr[d][j] = 0.5 * pr[d - j][j-1];
			if(j != G) pr[d][j] += 0.5 * pr[d + j][j - 1];

			//cout << dp[d][j]
		}
	}

	forsn(j,1,6)
	{
		for(int d = -10; d <= 10; d++)
		{
			cout << pr[d + 5000][j] << " ";
		}
		cout << endl;
	}

	double ans = 0.0;
	
	forn(i,2*G) ans += pr[5000+i][N];
	cout << 2.0 * ans << endl;
	return (2.0 * ans);
}

int main()
{
	int N,G; cin >> N >> G;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(3);
	double p = doesItMatter(N,G);
	return 0;
}