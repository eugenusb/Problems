#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)
#define R real
#define I imag
#define F first
#define S second

using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

char tab[1010][1010];
vector<par> adj[1010][1010];

int main()
{
	int t,n,m; cin >> t;

	forsn(caso, 1, t+1)	
	{
		cin >> n >> m;

		forn(i,n)
		{
			forn(j,m)
			{
				cin >> tab[i][j];
				adj[i][j].clear();				
			}
		}

		//vector< vector<par> > adj(n, vector<par>(m));

		forn(i,n)
		{
			int j = 0;

			while(j < m)
			{
				if(tab[i][j] != '#')
				{
					int init = j;
					while((j < m) and tab[i][j] != '#')
					{
						j++;
					}
					int fin = j-1;
					while(init < fin)
					{
						adj[i][init].pb(mp(i,fin));
						adj[i][fin].pb(mp(i,init));
						init++; fin--;
					}
				}
				else
				{
					j++;
				}
			}
		}

		forn(j,m)
		{
			int i = 0;

			while(i < n)
			{
				if(tab[i][j] != '#')
				{
					int init = i;
					while((i < n) and tab[i][j] != '#')
					{
						i++;
					}
					int fin = i-1;
					while(init < fin)
					{
						adj[init][j].pb(mp(fin,j));
						adj[fin][j].pb(mp(init,j));
						init++; fin--;
					}
				}
				else
				{
					i++;
				}
			}
		}

		vector< vector<int> > vis(n, vector<int>(m,0));

		queue<par> Q;
		string letters = "#";

		int comp = 1;
		forn(i,n)
		{
			forn(j,m)
			{
				if(vis[i][j] != 0) continue;
				if(tab[i][j] == '#') continue;

				vis[i][j] = comp;
				Q.push(mp(i,j));

				char c = tab[i][j];

				while(!Q.empty())
				{
					par cur = Q.front();
					Q.pop();
					int u = cur.F; int v = cur.S;					

					fora(p, adj[u][v])
					{
						if(!vis[p.F][p.S])
						{
							vis[p.F][p.S] = comp;
							Q.push(p);

							if(tab[p.F][p.S] != '.') c = tab[p.F][p.S];
						}
					}
				}
				letters += c;
				comp++;
			}
		}

		int ans = 0;

		forn(i,n)
		{
			forn(j,m)
			{
				if(tab[i][j] != letters[vis[i][j]]) ans++;
				tab[i][j] = letters[vis[i][j]];
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
		forn(i,n)
		{
			forn(j,m)
			{
				cout << tab[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}