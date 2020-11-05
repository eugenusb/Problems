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


int main()
{
	int t,n;
	cin >> t;
	double p;

	forsn(caso,1,t+1)
	{
		cin >> n >> p;
		double Pr[n+1][n+1][n+1];

		forn(i,n+1) forn(j,n+1) forn(k,n+1) Pr[i][j][k] = 0.0;
		forn(i,n) Pr[i+1][0][i] = 1.0;

		forsn(i,1,n+1)
		{
			forn(j,n)
			{
				forn(k,i)
				{
					double a = (n-j-1-k) * p + (n-j-1-k) *(n-j-1-k-1)/2.0 + k*(n-j-1-k)*p;
					double b = (k+1)*(1-p) + (k+1)*k/2.0 + (k+1)*(n-j-1-k-1)*(1-p);

					Pr[i][j+1][k] = 2.0/( (n-j) * (n-j-1) ) * (a * Pr[i][j][k] + b * Pr[i][j][k+1]);

					cout << i << " " << j+1 << " " << k << " " << Pr[i][j+1][k] << endl;
				}
			}
		}

		forsn(i,1,n+1)
		{
			forsn(j,1,n+1)
			{
				double pij = 0.0;
				forn(k,i)
				{
					pij += Pr[i][j][k];
				}
				cout << i << " " << j << " " << pij << endl;
			}
		}

		//cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}