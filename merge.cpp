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

vector< par > adj[10100][2];

int dp[10100][2];
bool vis[10100][2];

void dfs(int v, int tr)
{
	vis[v][tr] = true;

	fora(p, adj[v][tr])
	{
		int u = p.F;
		int pos = p.S;

		if(!vis[u][tr])
		{
			dfs(u, tr);
		}

		if(pos == 0) dp[v][tr] = 1 + dp[u][tr];
	}
}


int main()
{
	int n;
	cin >> n;
	int v,l,c;
	forn(i,n)
	{
		cin >> v >> l >> c;
		if(l)
		{
			adj[v][0].pb(mp(l,1));
		}
		if(c)
		{
			adj[v][0].pb(mp(c,0));
		}
	}
	int m,r;
	cin >> m;
	forn(i,m)
	{
		cin >> v >> c >> r;
		if(r) adj[v][1].pb(mp(r,1));
		if(c) adj[v][1].pb(mp(c,0));
	}
	dfs(1,0);
	dfs(1,1);
	int maxR = 0; int maxL = 0;

	forn(i,n) maxL = max(maxL, dp[i+1][0]);
	forn(i,m) maxR = max(maxR, dp[i+1][1]);

	int cndL = n + m - (min(dp[1][0], maxR));
	int cndR = n + m - (min(dp[1][1], maxL));

	cout << min(cndL, cndR) - 1 << endl;

	return 0;
}