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
typedef pair<tint,tint> par;

unordered_map< string, vector< pair< string, par > > > adj;
unordered_map<string, tint> cost;
unordered_map<string, tint> value;
unordered_map<string, int> indeg;
unordered_map<string, int> outdeg;
unordered_set<string> nodes;
unordered_map<string, bool> vis;


void dfs(string v)
{
	vis[v] = true;

	tint cost_node = -1;
	tint val_node = -1;

	if(adj.find(v) == adj.end())
	{
		cost[v] = 0;
		value[v] = 0;
		return;
	}

	fora(info, adj[v])
	{
		string w = info.F;
		tint co = info.S.F;
		tint va = info.S.S;

		if(vis.find(w) == vis.end())
		{
			dfs(w);
		}

		if(cost_node == -1)
		{
			cost_node = co + cost[w];
			val_node = va + value[w];
		}
		else
		{
			if(cost_node > co + cost[w])
			{
				val_node = va + value[w];
				cost_node = co + cost[w];
			}
			else
			{
				if(cost_node == co + cost[w])
				{
					val_node = max(val_node, va + value[w]);
				}
			}
		}
	}

	cost[v] = cost_node;
	value[v] = val_node;
}

tint dp[2][10100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int b,n;
	cin >> b >> n;

	string dish1, dish2;
	char di1[20]; char di2[20]; char ingr[20];
	int cos, val;

	forn(i,n)
	{
		cin >> dish1 >> dish2 >> ingr >> cos >> val;
		//scanf("%s %s %s %d %d", di1, di2, ingr, &cos, &val);
		//dish1 = di1; dish2 = di2;
		adj[dish1].pb(mp(dish2, mp(cos,val)));
		if(indeg.find(dish2) == indeg.end())
			indeg[dish2] = 1;
		else indeg[dish2]++;
		if(outdeg.find(dish1) == outdeg.end())
			outdeg[dish1] = 1;
		else outdeg[dish1]++;
		nodes.insert(dish1);
		nodes.insert(dish2);
	}

	/*
	fora(v, nodes)
	{
		if(indeg.find(v) == indeg.end())
		{
			cost[v] = 0;
			value[v] = 0;
			vis[]
		}
	}
	*/

	fora(v,nodes)
	{
		if(indeg.find(v) == indeg.end())
		{
			dfs(v);
		}
	}

	int items = outdeg.size();

	vector<int> costo(items);
	vector<tint> valor(items);

	int ind = 0;

	fora(p, outdeg)
	{
		//cout << p.F << " " << cost[p.F] << " " << value[p.F] << endl;
		costo[ind] = cost[p.F];
		valor[ind] = value[p.F];
		ind++;
	}

	forn(w,b+1) dp[0][w] = 0;

	tint ans_v = 0;
	int ans_c = 0;

	forn(i, items)
	{
		int prev = (i & 1) ? 1 : 0;
		int ind = 1 - prev;
		//cout << i << " " << prev << endl;
		forn(w,b+1)
		{
			dp[ind][w] = dp[prev][w];
			if(w >= costo[i])
			{
				tint cnd = valor[i] + dp[prev][w - costo[i]];
				dp[ind][w] = max(dp[ind][w], cnd);

				if(cnd > ans_v)
				{
					ans_v = cnd;
					ans_c = w;
				}
				else
				{
					if(cnd == ans_v)
					{
						ans_c = min(ans_c, w);
					}
				}
			}
			/*
			cout << costo[i] << " " << valor[i] << " : " << endl;
			cout << "capacidad " << w << ": " << dp[ind][w] << endl;
			*/
		}
	}

	cout << ans_v << endl;
	cout << ans_c << endl;

	return 0;
}