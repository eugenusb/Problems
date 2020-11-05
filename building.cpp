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
	int t,n,a,b,c;
	cin >> t;

	forsn(caso, 1, t+1)
	{
		cin >> n >> a >> b >> c;
		vector<int> ans(n,1);
		bool ok = true;
		if(a + b - c > n) ok = false;
		else
		{
			if(c > 1)
			{
				forn(i,c-1) ans[a-c+i] = 2;
				ans[n-1-b+c] = 2;
			}
			else
			{
				// c = 1
				if(a + b - c == n)
				{
					ans[a-c] = 2;
				}
				else
				{
					if(a == 1 and b == 1)
					{
						ok = false;
					}
					else
					{
						forn(i,a-1) ans[i] = 2;
						forn(i,b-1) ans[n-1-i] = 2;
						if(a == 1)
						{
							ans[0] = 3;
						}
						else
						{
							if(b == 1)
							{
								ans[n-1] = 3;
							}
							else
							{
								ans[a] = 3;
							}
						}
					}
				}
			}
		}

		if(!ok) cout << "Case #" << caso << ": " << "IMPOSSIBLE" << endl;
		else
		{
			cout << "Case #" << caso << ": ";
			forn(i,n) cout << ans[i] << " ";
			cout << endl;
		}
	}

	return 0;
}