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

string mat[55];

int main()
{
	int t; cin >> t;
	int n;
	forn(caso, t)
	{
		cin >> n;
		forn(i,n) cin >> mat[i];

		bool ok = true;

		forn(i,n)
		{
			forn(j,n)
			{
				if(mat[i][j] == '1')
				{
					if(!(j + 1 == n or i + 1 == n or mat[i+1][j] == '1' or mat[i][j+1] == '1'))
					{
						ok = false;
						break;
					}
				}
			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}