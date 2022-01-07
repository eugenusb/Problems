#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define R real
#define I imag
#define sq(a) (a)*(a)
 
using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;


int main()
{
	int t; cin >> t;
	int x,y;

	forsn(caso,1,t+1)
	{
		cin >> x >> y;
		bool invx = (x < 0);
		bool invy = (y < 0);

		x = abs(x); y = abs(y);

		string ans = "";
		bool ok = true;

		while(true)
		{
			//cout << x << " " << y << endl;
			if(x == 0 and y == 1)
			{
				ans += "N";
				break;
			}
			if(x == 1 and y == 0)
			{
				ans += "E";
				break;
			}

			if(x & 1)
			{
				if(y & 1)
				{
					ok = false;
					break;
				}
				else
				{
					y /= 2;
					int s = y % 2;

					int u = (x + 1) / 2;

					if(u % 2 == s)
					{
						x = (x - 1) / 2;
						ans += "E";
					}
					else
					{
						x = u;
						ans += "W";
					}
				}
			}
			else
			{
				if(y & 1)
				{
					x /= 2;
					int s = x % 2;

					int u = (y + 1) / 2;
					
					if(u % 2 == s)
					{
						y = (y - 1) / 2;
						ans += "N";
					}
					else
					{
						y = u;
						ans += "S";
					}
				}
				else
				{
					ok = false;
					break;
				}
			}
		}

		cout << "Case #" << caso << ": ";
		if(ok)
		{
			if(invx)
			{
				forn(i, ans.size())
				{
					if(ans[i] == 'E')
					{
						ans[i] = 'W';
					}
					else
					{
						if(ans[i] == 'W')
						{
							ans[i] = 'E';
						}
					}
				}
			}
			if(invy)
			{
				forn(i, ans.size())
				{
					if(ans[i] == 'N')
					{
						ans[i] = 'S';
					}
					else
					{
						if(ans[i] == 'S')
						{
							ans[i] = 'N';
						}
					}
				}
			}
			cout << ans << endl;
		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}