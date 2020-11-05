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

par added[200100];
tint a[200100];
priority_queue< par > adj[200100];
pair< par, int > st[800100];

void init(int node, int l, int r)
{
	if(r == l + 1)
	{
		st[node] = mp(added[l], l);
		return;
	}

	int m = (l + r) / 2;

	init(2 * node, l, m);
	init(2* node + 1, m, r);

	if(st[2 * node] > st[2 * node + 1])
		st[node] = st[2 * node];
	else
		st[node] = st[2 * node + 1];

}


pair< par, int> query(int node, int l, int r, int a, int b)
{
	if(r <= a or b <= l) return (mp(mp(-1,-1),-1));

	if(a <= l and r <= b) return (st[node]);

	int m = (l + r) / 2;

	pair< par, int > p1 = query(2 * node, l, m, a, b);
	pair< par, int > p2 = query(2 * node + 1, m, r, a, b);

	return (max(p1,p2));
}

void update(int node, int l, int r, int pos, par val)
{
	if(r <= pos or pos < l) return;

	if(r == l + 1)
	{
		st[node] = mp(val, pos);
		return;
	}

	int m = (l + r) / 2;

	update(2 * node, l, m, pos, val);
	update(2 * node + 1, m, r, pos, val);

	st[node] = max(st[2 * node], st[2 * node + 1]);
}

int main()
{
	int n,m; tint w; tint acum = 0;
	
	cin >> n;
	init(1,0,2*n);
	a[0] = 0;

	forn(i,n)
	{
		cin >> w;
		acum += w;
		a[i+1] = a[i] + w;		
	}
	forn(i,n) a[i+n+1] = acum + a[i+1];

	cin >> m;

	int tipo, x, y; tint v = 2 * n;
	tint cnd; pair< par, int> res;
	/*
	cout << endl;
	forn(i,2*n+1) cout << a[i] << " ";
	cout << endl;
	*/
	forn(i,m)
	{
		cin >> tipo >> x;
		//cout << tipo << " " << x << endl;
		x--;				
		switch(tipo)
		{
			case 1:
				// search farthest node both in added segment tree and in a
				cin >> w;

				cnd = a[x-1+n];
				res = query(1,0,2*n,x,x+n);
				
				if(cnd > res.F.F)
				{
					y = x - 1 + n;
					par nuevo = mp(a[y] + w, v);
					adj[y].push(nuevo);
					added[y] = max(added[y], nuevo);
					update(1,0,2*n,y,added[y]);
					if(y < n) y += n;
					else y -= n;
					nuevo = mp(a[y] + w, v);
					adj[y].push(nuevo);
					added[y] = max(added[y], nuevo);
					update(1,0,2*n,y,added[y]);
				}				
				else
				{
					y = res.S;
					adj[y].push(mp(res.F.F + w, v));
					added[y] = max(added[y], mp(res.F.F + w, v));
					update(1,0,2*n,y,added[y]);
					if(y < n)
					{
						y += n;
						w += acum;
					}
					else
					{
						y -= n;
						w -= acum;
					}
					adj[y].push(mp(res.F.F + w, v));
					added[y] = max(added[y], mp(res.F.F + w, v));
					update(1,0,2*n,y,added[y]);
				}

				v++;
				break;
			case 2:
				cin >> w;

				// add new edge of weight w to x
				adj[x].push(mp(a[x] + w, v));
				adj[x+n].push(mp(a[x+n] + w, v));

				// update the segment tree
				added[x] = max(added[x], mp(a[x]+w, v));
				update(1,0,2*n,x,added[x]);
				added[x+n] = max(added[x+n], mp(a[x+n]+w,v));
				update(1,0,2*n,x+n,added[x+n]);

				// update v
				v++;
				break;
			case 3:
				// search in added segment tree
				res = query(1,0,2*n,x,x+n);
				y = res.S;
				//cout << res.F.F << " " << res.F.S << " " << y << " " << added[y].F << " " << added[y].S << endl;
				assert(!adj[y].empty());
				adj[y].pop();
				if(!adj[y].empty())
				{					
					added[y] = adj[y].top();
					update(1,0,2*n,y,added[y]);
					if(y < n) y += n;
					else y -= n;
					adj[y].pop();
					added[y] = adj[y].top();
					update(1,0,2*n,y,added[y]);
				}
				else
				{
					added[y] = mp(0,0);
					update(1,0,2*n,y,added[y]);
					if(y < n) y += n;
					else y -= n;
					adj[y].pop();
					added[y] = mp(0,0);
					update(1,0,2*n,y,added[y]);
				}

				break;
			case 4:
				// search farthest node both in added segment tree and in a
				cnd = a[x-1+n];
				res = query(1,0,2*n,x,x+n);

				//cout << cnd << " " << res.F.F << " " << res.F.S << " " << res.S << endl;
				tint ans = max(cnd, res.F.F);

				if(x) ans -= a[x];
				cout << ans << endl;
				break;
		}
		/*
		forn(j, 2*n)
		{			
			priority_queue< par > temp = adj[j];
			
			if(!adj[j].empty())
			{
				cout << j << ": " << endl;
			    while(!temp.empty())
			    {
			    	par p = temp.top();
			    	cout << "(" << p.F << ", " << p.S << ") ";
			    	temp.pop();
			    }

				cout << endl;
			}			
		}
		*/
	}

	return 0;
}