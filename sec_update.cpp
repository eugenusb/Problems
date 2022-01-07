#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;

vector<int> adj[110];

int dist[110][110];

const int INF = (int)(1e6);

int main()
{
	int t; cin >> t;
	int c,d;

	forsn(caso,1,t+1)
	{
		cin >> c >> d;
		int u,v;
		vector<par> di;
		vector<par> neg;
		vector<par> edges;
		forn(i,101) adj[i].clear();
		forsn(i,1,c+1)
		{
			forsn(j,1,c+1)
			{
				dist[i][j] = -1;
			}
		}
		forsn(i,2,c+1)
		{
			int x; cin >> x;

			if(x > 0)
			{
				di.pb(mp(x,i));
			}
			else
			{
				neg.pb(mp(x,i));
			}
		}
		forn(i,d)
		{
			cin >> u >> v;
			dist[u][v] = INF;
			dist[v][u] = INF;
			//cout << u << " " << v << " " << dist[u][v] << endl;
			edges.pb(mp(u,v));
		}

		sort(di.begin(), di.end());
		sort(neg.begin(), neg.end());
		reverse(neg.begin(), neg.end());

		vector<par> lista;

		int ind1 = 0; int ind2 = 0;
		int cant = 1;

		int disz = (int) (di.size());
		int negsz = (int) (neg.size());

		while(ind1 < disz or ind2 < negsz)
		{
			//cout << ind1 << " " << ind2 << " " << cant << endl;
			if(ind1 == disz)
			{
				forsn(j,ind2,negsz)
				{
					lista.pb(neg[j]);
				}
				ind2 = negsz;
			}
			else
			{
				if(ind2 == negsz)
				{
					forsn(j,ind1,disz)
					{
						lista.pb(di[j]);
					}
					ind1 = disz;
				}
				else
				{
					//ind1 , ind2 disponibles

					if(neg[ind2].F == -cant)
					{
						while(ind2 < negsz and neg[ind2].F == -cant)
						{
							lista.pb(neg[ind2]);
							ind2++;
						}
					}
					else
					{
						int cur = di[ind1].F;

						while(ind1 < disz and di[ind1].F == cur)
						{
							lista.pb(di[ind1]);
							ind1++;
						}
					}

					cant = (int) (lista.size()); cant++;
				}
			}
		}

		int ind = 0;
		int totdi = 0;
		vector<int> tr(c+1,-1);
		tr[1] = 0;
		set<int> intr;
		intr.insert(1);

		while(ind < c-1)
		{
			int an = lista[ind].F;
			vector<par> aux;

			while(ind < c - 1 and lista[ind].F == an)
			{
				aux.pb(lista[ind]);
				ind++;
			}
			//cout << " iter " << an << endl;
			fora(p, aux)
			{               
				int v = p.S;
				
				int w;
				bool se = false;
				int mini = -1;

				forn(u,c+1)
				{                   
					if(dist[u][v] != INF) continue;
					if(intr.find(u) != intr.end())
					{
						if(se)
						{
							if(mini > tr[u])
							{
								w = u;
								mini = tr[u];
							}
						}
						else
						{
							se = true;
							mini = tr[u];
							w = u;
						}
					}
				}
				
				if(an < 0)
				{
					dist[v][w] = totdi + 1 - mini;
					dist[w][v] = totdi + 1 - mini;
					tr[v] = totdi + 1;
					intr.insert(v);
				}
				else
				{
					dist[v][w] = an - mini;
					dist[w][v] = an - mini;
					tr[v] = an;
					intr.insert(v);
				}

				//cout << v << " " << w << " " << mini << " " << dist[v][w] << " " << dist[w][v] << endl;
			}

			if(an < 0) totdi++;
			else totdi = an;
		}

		vector<int> ans;

		fora(e, edges)
		{
			//cout << e.F << " " << e.S << " " << dist[e.F][e.S] << endl;
			ans.pb(dist[e.F][e.S]);
		}

		cout << "Case #" << caso << ": ";
		forn(i,d-1) cout << ans[i] << " ";
		cout << ans[d-1] << endl;
	}

	return 0;
}