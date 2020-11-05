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

struct tab
{
	par pos_a;
	par pos_b;
	int s;
	bool turn;
	bool room[6][11];

	tab(par pos_a, par pos_b, int s, bool turn) : pos_a(pos_a), pos_b(pos_b), s(s), turn(turn)
	{
		forn(i,6)
			forn(j,11)
				room[i][j] = 0;

		room[pos_a.F][pos_a.S] = true;
		room[pos_b.F][pos_b.S] = true;
	}
};

bool operator<(const tab& t1, const tab& t2) 
{ 
    int s = t1.s;

    forn(i,s)
    {
    	forn(j,2*i+1)
    	{
    		if(t1.room[i][j] != t2.room[i][j])
    			return (t1.room[i][j] < t2.room[i][j]);
    	}
    }

    if(t1.pos_a != t2.pos_a)
    	return (t1.pos_a < t2.pos_a);
    if(t1.pos_b != t2.pos_b)
    	return (t1.pos_b < t2.pos_b);
    if(t1.turn != t2.turn)
    	return (t1.turn < t2.turn);

    return (false);
}


void print(const tab& t)
{ 
    cout << t.pos_a.F << " " << t.pos_a.S << endl;
    cout << t.pos_b.F << " " << t.pos_b.S << endl;
	cout << t.turn << endl;

    forn(i,t.s)
    {
    	forn(j,2*i+1)
    	{
    		cout << t.room[i][j];
    	}
    	cout << endl;
    }
}

map<tab, int> dp;
const int INF = (int)(1e7);

int dp_calc(bool turn, int xa, int ya, int xb, int yb, tab t, int s)
{
	// check movements for both

	/*cout << xa << " " << ya << " " << xb << " " << yb << " " << turn << endl;
	print(t);
	
	fora(tt,dp)
	{
		print(tt.F);
	}
	*/
	if(dp.find(t) != dp.end())
	{
		return (dp[t]);
	}

	int tot = 0;
	if(ya)
	{
		if(!t.room[xa][ya-1])
		{
			tot++;
		}
	}

	if(ya < 2*xa)
	{
		if(!t.room[xa][ya+1])
		{
			tot++;
		}
	}

	if(ya & 1)
	{
		if(!t.room[xa-1][ya-1])
		{
			tot++;
		}
	}
	else
	{
		if(xa < (s-1) and !t.room[xa+1][ya+1])
		{
			tot++;
		}
	}

	if(yb)
	{
		if(!t.room[xb][yb-1])
		{
			tot++;
		}
	}

	if(yb < 2*xb)
	{
		if(!t.room[xb][yb+1])
		{
			tot++;
		}
	}

	if(yb & 1)
	{
		if(!t.room[xb-1][yb-1])
		{
			tot++;
		}
	}
	else
	{
		if(xb < (s-1) and !t.room[xb+1][yb+1])
		{
			tot++;
		}
	}

	if(tot == 0)
	{
		dp[t] = 0;
		return (0);
	}

	if(turn == 0)
	{
		turn = 1;
		int ans = -INF;

		if(ya)
		{
			if(!t.room[xa][ya-1])
			{
				tab tnew(mp(xa,ya-1),mp(xb,yb),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xa][ya-1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya-1,xb,yb,tnew,s);
					dp[tnew] = u;
				}
				ans = max(ans,1 + dp[tnew]);
			}
		}

		if(ya < 2*xa)
		{
			if(!t.room[xa][ya+1])
			{
				tab tnew(mp(xa,ya+1),mp(xb,yb),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xa][ya+1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya+1,xb,yb,tnew,s);
					dp[tnew] = u;
				}
				ans = max(ans,1 + dp[tnew]);
			}
		}

		if(ya & 1)
		{
			if(!t.room[xa-1][ya-1])
			{
				tab tnew(mp(xa-1,ya-1),mp(xb,yb),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xa-1][ya-1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa-1,ya-1,xb,yb,tnew,s);
					dp[tnew] = u;
				}
				ans = max(ans,1 + dp[tnew]);
			}
		}
		else
		{
			if(xa < (s-1) and !t.room[xa+1][ya+1])
			{
				tab tnew(mp(xa+1,ya+1),mp(xb,yb),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xa+1][ya+1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa+1,ya+1,xb,yb,tnew,s);
					dp[tnew] = u;
				}
				ans = max(ans,1 + dp[tnew]);
			}
		}

		if(ans == -INF)
		{
			// no place to go
			tab tnew(mp(xa,ya),mp(xb,yb),s,turn);
			forn(i,6)
			{
				forn(j,11)
				{
					tnew.room[i][j] = t.room[i][j];
				}
			}

			if(dp.find(tnew) == dp.end())
			{
				int u = dp_calc(turn,xa,ya,xb,yb,tnew,s);
				dp[tnew] = u;
			}
			ans = dp[tnew];
			dp[t] = dp[tnew];
		}
		else dp[t] = ans;
		return (ans);
	}
	else
	{
		turn = 0;
		int ans = INF;

		if(yb)
		{
			if(!t.room[xb][yb-1])
			{
				tab tnew(mp(xa,ya),mp(xb,yb-1),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xb][yb-1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya,xb,yb-1,tnew,s);
					dp[tnew] = u;
				}
				ans = min(ans,-1 + dp[tnew]);
			}
		}

		if(yb < 2*xb)
		{
			if(!t.room[xb][yb+1])
			{
				tab tnew(mp(xa,ya),mp(xb,yb+1),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xb][yb+1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya,xb,yb+1,tnew,s);
					dp[tnew] = u;
				}
				ans = min(ans, -1 + dp[tnew]);
			}
		}

		if(yb & 1)
		{
			if(!t.room[xb-1][yb-1])
			{
				tab tnew(mp(xa,ya),mp(xb-1,yb-1),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xb-1][yb-1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya,xb-1,yb-1,tnew,s);
					dp[tnew] = u;
				}
				ans = min(ans, -1 + dp[tnew]);
			}
		}
		else
		{
			if(xb < (s-1) and !t.room[xb+1][yb+1])
			{
				tab tnew(mp(xa,ya),mp(xb+1,yb+1),s,turn);
				forn(i,6)
				{
					forn(j,11)
					{
						tnew.room[i][j] = t.room[i][j];
					}
				}

				tnew.room[xb+1][yb+1] = true;

				if(dp.find(tnew) == dp.end())
				{
					int u = dp_calc(turn,xa,ya,xb+1,yb+1,tnew,s);
					dp[tnew] = u;
				}
				ans = min(ans, -1 + dp[tnew]);
			}
		}

		if(ans == INF)
		{
			// no place to go
			tab tnew(mp(xa,ya),mp(xb,yb),s,turn);
			forn(i,6)
			{
				forn(j,11)
				{
					tnew.room[i][j] = t.room[i][j];
				}
			}
			//cout << "B encerrado" << endl;
			if(dp.find(tnew) == dp.end())
			{
				int u = dp_calc(turn,xa,ya,xb,yb,tnew,s);
				dp[tnew] = u;
			}
			ans = dp[tnew];
			dp[t] = dp[tnew];
		}
		else dp[t] = ans;
		return (ans);
	}
}

int main()
{
	int t,s,ra,ca,rb,cb,c,ro,co;
	cin >> t;

	forsn(caso,1,t+1)
	{
		dp.clear();
		cin >> s >> ra >> ca >> rb >> cb >> c;
		ra--; ca--; rb--; cb--;
		tab initial(mp(ra,ca),mp(rb,cb),s,0);
		forn(i,c)
		{
			cin >> ro >> co;
			ro--; co--;
			initial.room[ro][co] = true; 
		}

		int ans = dp_calc(0,ra,ca,rb,cb,initial,s);

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}