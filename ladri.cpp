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

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};

int tab[210][210];
bool vis[210][210];

bool valid(int a, int b, int n, int m)
{
	return ((0 <= a) and (a < n) and (0 <= b) and (b < m));
}

int bfs(int u, int v, int n, int m)
{
	queue<par> Q;
	Q.push({u,v});
	int COLOR = tab[u][v];
	int cnt = 0;
	vis[u][v] = true;

	while(!Q.empty())
	{
		par cur = Q.front(); Q.pop();
		cnt++;

		forn(i,4)
		{
			int a = cur.F + dx[i];
			int b = cur.S + dy[i];

			if(valid(a,b,n,m) and !vis[a][b] and tab[a][b] == COLOR)
			{
				vis[a][b] = true;
				Q.push({a,b});
			}
		}

	}

	return (cnt);
}

int main()
{
	int n,m;
	cin >> n >> m;

	forn(i,n)
	{
		forn(j,m)
		{
			cin >> tab[i][j];
		}
	}

	int ans = n*m;

	forn(i,n)
	{
		forn(j,m)
		{
			if(!vis[i][j])
			{
				int cnd = bfs(i,j,n,m);
				ans = min(ans, cnd);
			}
		}
	}

	cout << ans << endl;

	return 0;
}