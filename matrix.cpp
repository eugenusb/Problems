#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;


int main()
{
	int t; cin >> t;
	int n,m,a,b;
	forn(caso, t)
	{
		cin >> n >> m >> a >> b;

		if(n * a == m * b)
		{
			cout << "YES" << endl;
			int ans[n][m];
			forn(i,n) forn(j,m) ans[i][j] = 0;

			forn(i,n)
			{
				forn(j,a)
				{
					int q = i / b;
					ans[i][j + a * q ] = 1;
				}
			}

			forn(i,n)
			{
				forn(j,m)
				{
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
		else cout << "NO" << endl;
	}

	return 0;
}