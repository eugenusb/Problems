#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

int f[100100];

int find(int v)
{
    return (f[v] == -1 ? v : f[v] = find(f[v]));
}

bool join(int i, int j)
{
    bool con = (find(i) == find(j));
    if(!con)
    {
        f[find(i)] = find(j);
    }

    return con;
}

vector<int> adj[100100];
bool vis[100100];

int dfs(int v)
{
    vis[v] = true;
    int ans = 1;
    forn(i, adj[v].size())
    {
        int u = adj[v][i];

        if(!vis[u])
        {
            ans += dfs(u);
        }
    }

    return (ans);
}

int main()
{
	int t; cin >> t;
    int n,m,a,b;

    forsn(caso,1,t+1)
    {
        cin >> n >> m;
        forn(i,n)
        {
            vis[i+1] = false;
            adj[i+1].clear();
        }
        forn(j,m)
        {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }
        int ans = 0;
        int comp = 0;

        forn(i,n)
        {
            int v = i+1;

            if(!vis[v])
            {
                comp++;
                int vert = dfs(v);
                ans += (vert - 1);
            }
        }
        ans += 2 * (comp - 1);

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}