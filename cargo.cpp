#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define zero(v) memset(v, 0, sizeof(v))
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

const int INF = (int)(1e9);

struct edge
{
	int u, v;
	int cap;
	int flow;
	int cost;
};

vector<int> adj[2010];
vector<edge> e;

void addEdge(int u, int v, int cap, int cost)
{
	adj[u].pb((int)e.size()); e.pb((edge){u,v,cap,0,cost});
	adj[v].pb((int)e.size()); e.pb((edge){v,u,0,0,-cost});
}

int dist[2010];
int pre[2010];
int cap[2010];
int pot[2010];

int mincost_flow(int s, int t, int n, int lim, int k, int c_max)
{
	int mxFlow = 0; int mnCost = 0;
	forn(i,n) pot[i] = 0;
	forn(i,e.size())
	{
		e[i].flow = 0;
		if(e[i].cost == 0)
		{
			e[i].cap = lim + 1;
		}
	}

	while(mxFlow < k)
	{
		fill(dist, dist + n, INF); dist[s] = 0;
		memset(pre, -1, sizeof(pre)); pre[s] = 0;
		zero(cap); cap[s] = INF;		
		priority_queue < par, vector< par >, greater< par > > Q;
		Q.push(mp(s,0));

		while(!Q.empty())
		{
			par p = Q.top(); Q.pop();
			int u = p.S; int d = p.F;
			if(d != dist[u]) continue;
			//cout << u << " " << d << endl;
			fora(w, adj[u])
			{
				edge &E = e[w];
				//cout << E.u << " " << E.v << " " << E.cap << " " << E.flow << " " << E.cost << endl;
				int rem = E.cap - E.flow;
				
				if(rem and dist[E.v] > d + pot[u] - pot[E.v] + E.cost)
				{
					dist[E.v] = d + pot[u] - pot[E.v] + E.cost;
					pre[E.v] = w;
					cap[E.v] = min(rem, cap[u]);
					Q.push(mp(dist[E.v], E.v));
				}
			}
		}

		forn(i,n)
		{
			pot[i] += dist[i];
		}

		if (pre[t] == -1) break;
		cap[t] = min(cap[t], k - mxFlow);		
		mxFlow += cap[t];

		for (int v = t; v != s; v = e[pre[v]].u)
		{
			mnCost += cap[t] * e[pre[v]].cost;
			e[pre[v]].flow += cap[t];
			e[pre[v]^1].flow -= cap[t];
		}

		if(mnCost > c_max) break;
	}

	return (mnCost);
}

int main() 
{
	int n,m,k,t,u,v;

	cin >> n >> m >> k >> t;

	forn(i,m)
	{
		cin >> u >> v;
		addEdge(u,v,0,0);
		addEdge(u,v,INF,1);
		addEdge(v,u,INF,1);
	}

	int lo = -1; int hi = k-1;

	while(hi - lo > 1)
	{
		int med = (lo + hi) / 2;
		int cost = mincost_flow(0,n-1,n,med,k,t);
		//cout << med << " " << cost << endl;
		if(cost <= t)
		{
			hi = med;
		}
		else
		{
			lo = med;
		}
	}

	cout << hi << endl;

	return 0;
} 
