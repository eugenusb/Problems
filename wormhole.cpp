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
par hole[110];
int parent[110];
int sz[110];


void init(int n)
{
	forn(v,n)
	{
		parent[v] = v;
		sz[v] = 1;
	}
}

int find(int v)
{
	if(v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a != b)
    {
		if(sz[a] < sz[b])
			swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}


int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int t; cin >> t;
	int n;

	forsn(caso, 1, t+1)
	{
		cin >> n;
		int x,y;
		forn(i,n)
		{
			cin >> hole[i].F >> hole[i].S;
		}

		map<par, vector< par > > edges;

		forn(i,n)
		{
			forn(j,n)
			{
				if(i == j) continue;
				par dir = mp(hole[j].F - hole[i].F, hole[j].S - hole[i].S);				
				int d = gcd(abs(dir.F), abs(dir.S));
				dir = mp(dir.F/d, dir.S/d);

				if(dir.F < 0)
				{
					dir = mp(-dir.F, -dir.S);
				}

				edges[dir].pb(mp(i,j));
			}
		}		

		int ans = 1;

		fora(p, edges)
		{
			init(n);
			auto edge_list = p.second;

			//cout << " DIRECTION " << p.F.F << " " << p.F.S << endl;

			fora(q, edge_list)
			{
				int u = q.F;
				int v = q.S;
				//cout << u << " " << v << endl;
				join(u,v);
			}
			//forn(v,n) sz[v] = sz[find(v)];
			int cnd = 0;
			int i;
			vector<bool> seen(n,false);
			vector<int> comp;
			int odd = 0;
			int even = 0;
			int ones = 0;
			int c_odd = 0;
			int c_even = 0;

			forn(v,n)
			{
				int p = find(v);
				if(seen[p]) continue;
				int s = sz[p];
				if(s == 1) ones++;
				else
				{
					if(s & 1) odd += s;
					else even += s;
				}
				comp.pb(sz[p]);
				seen[p] = true;
			}
			if( (odd + even) & 1)
			{
				cnd = odd + even + min(1,ones);
			}
			else
			{
				cnd = odd + even + min(2,ones);
			}
			//cout << " CND " << cnd << endl;
			ans = max(ans, cnd);
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}