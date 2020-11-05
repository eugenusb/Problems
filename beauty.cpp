#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

vector<int> adj[100100];
tint b[100100];
tint dp[100100][3]; //0 = No iluminado, 1 = Iluminado y apagado, 2 = Iluminado y prendido
bool vis[100100];
const tint INF = (tint)(1e11);

void dfs(int v)
{
    vis[v] = true;

    tint acum0 = 0;
    tint acum1 = b[v];
    tint acum2 = b[v];
    int ch = 0;
    tint best = -INF;

    forn(i, adj[v].size())
    {
        int u = adj[v][i];

        if(!vis[u])
        {
            ch++;
            dfs(u);
            acum0 += max(dp[u][0], dp[u][1]);
            tint loc = dp[u][0];
            forn(i,3) loc = max(loc, dp[u][i]);
            best = max(best, dp[u][2] - loc);
            acum1 += loc;
            loc = max(dp[u][1], dp[u][2]);
            loc = max(loc, b[u] + dp[u][0]);
            acum2 += loc;
        }
    }

    if(ch) dp[v][1] = acum1 + best;
    else dp[v][1] = -INF;

    dp[v][0] = acum0;
    dp[v][2] = acum2;
    /*
    cout << "Vertice " << v << endl;
    forn(i,3)
    {        
        cout << dp[v][i] << " ";
    }
    cout << endl;
    */
}

int main()
{
	int t; cin >> t;
	int n; int u,v;

    forsn(caso,1,t+1)
    {
    	cin >> n;
        forn(i,n)
        {
            adj[i+1].clear();
            vis[i+1] = false;
            cin >> b[i+1];
        }
        forn(i,n-1)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);            
        }
        dfs(1);
        tint ans = dp[1][0];
        forn(i,3) ans = max(ans, dp[1][i]);

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}