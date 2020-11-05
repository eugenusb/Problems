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
typedef pair<tint,int> par;


struct vertex
{
	int tab[2][4];
	vertex()
	{
		forn(i,2)
		{
			forn(j,4)
			{
				tab[i][j] = 0;
			}
		}
	}
};

bool operator<(const vertex& t1, const vertex& t2) 
{ 
    forn(i,2)
    {
    	forn(j,4)
    	{
    		if(t1.tab[i][j] != t2.tab[i][j])
    			return (t1.tab[i][j] < t2.tab[i][j]);
    	}
    }
    return (false);
}

vector< vertex > ve;
map< vertex, int > code;
tint dist[40500];
const tint INF = (tint)(1e16);

void dijkstra(vertex v)
{
	dist[code[v]] = 0;

	priority_queue< par, vector< par > , std::greater< par > > Q;

	Q.push(mp(0,code[v]));

	while(!Q.empty())
	{
		par cnd = Q.top(); Q.pop();
		tint d = cnd.F; int id = cnd.S;		
		vertex cur = ve[id];
		/*
		cout << d << " " << id << endl;
		forn(i,2)
		{
			forn(j,4)
			{
				cout << cur.tab[i][j] << " ";
			}
			cout << endl;
		}
		*/
		if(dist[id] < d) continue;		

		forn(i,2)
		{
			forn(j,4)
			{
				vertex vec;
				forn(u,2)
				{
					forn(v,4)
					{
						vec.tab[u][v] = cur.tab[u][v];
					}
				}
				if(j < 3)
				{
					swap(vec.tab[i][j], vec.tab[i][j+1]);
					int u = code[vec];
					tint cost = vec.tab[i][j] + vec.tab[i][j+1];

					if(dist[u] > dist[id] + cost) 
		            { 
		                dist[u] = dist[id] + cost;
		                Q.push(mp(dist[u], u)); 
		            }

					swap(vec.tab[i][j], vec.tab[i][j+1]);
				}
				if(i == 0)
				{
					swap(vec.tab[i][j], vec.tab[i+1][j]);
					tint cost = vec.tab[i][j] + vec.tab[i+1][j];

					int u = code[vec];
					
					if(dist[u] > dist[id] + cost) 
		            { 
		                dist[u] = dist[id] + cost;
		                Q.push(mp(dist[u], u)); 
		            }

					swap(vec.tab[i][j], vec.tab[i+1][j]);	
				}
			}
		}
	}
}

int main()
{
	vertex initial; vertex final;
	
	forn(i,2)
	{
		forn(j,4)
		{
			cin >> initial.tab[i][j];
		}
	}
	forn(i,2)
	{
		forn(j,4)
		{
			cin >> final.tab[i][j];
		}
	}

	int a[8];
	forn(i,2)
	{
		forn(j,4)
		{
			a[4*i+j] = initial.tab[i][j];
		}
	}
	sort(a,a+8);

	int c = 0;

	do
	{
		vertex v;
		forn(i,2)
		{
			forn(j,4)
			{
				v.tab[i][j] = a[4*i+j];
			}
		}
		ve.pb(v);
		code[v] = c;
		dist[c] = INF;
		c++;
	} while(next_permutation(a,a+8));

	dijkstra(initial);
	tint ans = dist[code[final]];

	cout << ans << endl;

	return 0;
}