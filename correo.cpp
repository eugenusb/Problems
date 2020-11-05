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

const int INF = (int)(1e9);
par che[1010];
par totin[1010];

int dist(par a, par b)
{
	int ans = abs(a.F - b.F) + abs(a.S - b.S);

	return (ans);
}

int calc(par pibe, par vino, par resto)
{
	int tot = 2 * dist(vino, resto);
	int cnd = dist(pibe, vino) + dist(vino, resto);

	int ans = tot - cnd;

	return (ans);
}

int hungarian(vector< vector<int> > &a, int n, int m)
{
	vector<int> u (n+1), v (m+1), p (m+1), way (m+1);

	cout << n << endl;

	forsn(i,1,n+1)
	{
		p[0] = i;
		int j0 = 0;
		vector<int> minv (m+1, INF);
		vector<bool> used (m+1, false);
		do
		{
			used[j0] = true;
			int i0 = p[j0],  delta = INF,  j1;
			forsn(j,1,m+1)
			{
				if(!used[j])
				{
					int cur = a[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			}
			forn(j,m+1)
				if (used[j])
					u[p[j]] += delta,  v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);
		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	int cost = -v[0];

	vector<int> ans (n+1, 0);
	forsn(j,1,m+1)
		ans[p[j]] = j;

	/*
	forsn(j,1,m+1)
	{
		if(p[j])
		{
			cout << totin[p[j]-1].F << " " << totin[p[j]-1].S << " : " << che[j-1].F << " " << che[j-1].S << endl;
		}
	}
	*/
	return (cost);
}

int main()
{
	int n,m;
	cin >> n >> m;

	forn(i,n) cin >> totin[i].F >> totin[i].S;
	forn(i,m) cin >> che[i].F >> che[i].S;

	par resto;
	cin >> resto.F >> resto.S;

	int ans = 0;
	forn(i,n)
	{
		ans += 2 * dist(totin[i], resto);
	}

	int dim = max(n,m);
	vector< vector<int> > a(dim+1, vector<int>(dim+1, 0));

	int max_save = -INF;

	forn(i,n)
	{
		forn(j,m)
		{
			int save = calc(che[j], totin[i], resto);
			max_save = max(save, max_save);
			if(save > 0) a[i+1][j+1] = save;
		}
	}

	if(max_save < 0)
	{
		// conviene siempre ir desde el restaurante. Minimizo costo de llegar
		ans -= max_save;
	}
	else
	{
		int opt = hungarian(a, dim, dim);
		ans -= opt;
	}
	
	cout << ans << endl;

	return 0;
}