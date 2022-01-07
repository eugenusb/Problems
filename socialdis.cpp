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
typedef pair<double,double> punto;

double x[1100];
double y[1100];
double le[1100];
double ri[1100];
double bot[1100];
double top[1100];

const double EPS = (1e-6);
double X,Y;

double dis(punto a, punto b)
{
	double ans = sqrt(sq(a.F - b.F) + sq(a.S - b.S));

	return (ans);
}

bool can(int n, double m)
{
	vector< vector<int> > adj(5*n+10);
	forn(i,n)
	{
		forn(j,i)
		{
			double c = dis(mp(x[i],y[i]),mp(x[j],y[j]));
			if(c < 2*m)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	forsn(i,n,2*n)
	{
		forn(j,n)
		{
			double c = dis(mp(0,le[i]),mp(x[j],y[j]));
			if(c < 2*m)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	forsn(i,2*n,3*n)
	{
		forn(j,n)
		{
			double c = dis(mp(X,ri[i]),mp(x[j],y[j]));
			if(c < 2*m)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	forsn(i,3*n,4*n)
	{
		forn(j,n)
		{
			double c = dis(mp(top[i],0),mp(x[j],y[j]));
			if(c < 2*m)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	forsn(i,4*n,5*n)
	{
		forn(j,n)
		{
			double c = dis(mp(bot[i],Y),mp(x[j],y[j]));
			if(c < 2*m)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}

	queue<int> Q;
	vector<int> vis(5*n,0);


	int L = 1;
	forsn(i,n,2*n)
	{
		Q.push(i);
		vis[i] = L;
	}

	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		if(cur >= 4*n) return false;
		if(2*n <= cur and cur < 3*n) return false;
		fora(v,adj[cur])
		{
			if(vis[v] < L)
			{
				Q.push(v);
				vis[v] = L;
			}
		}
	}

	L++;
	forsn(i,3*n,4*n)
	{
		Q.push(i);
		vis[i] = L;
	}

	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		if(cur >= 4*n) return false;
		if(2*n <= cur and cur < 3*n) return false;
		fora(v,adj[cur])
		{
			if(vis[v] < L)
			{
				Q.push(v);
				vis[v] = L;
			}
		}
	}

	return true;
}

int main()
{
	int n;
	cin >> X >> Y;
	cin >> n;
	double hi = 2*sqrt(sq(X) + sq(Y));
	punto org = mp(0,0);

	forn(i,n)
	{
		cin >> x[i] >> y[i];
		bot[i] = x[i];
		top[i] = x[i];
		le[i] = y[i];
		ri[i] = y[i];
		hi = min(hi, dis(mp(x[i],y[i]),org));
		hi = min(hi, dis(mp(x[i],y[i]),mp(X,Y)));
	}

	double lo = 0;

	while(hi - lo > EPS)
	{
		double med = (lo + hi) / 2.0;

		if(can(n,med))
		{
			hi = med;
		}
		else
		{
			lo = med;
		}
	}

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(10);

	cout << hi << endl;

	return 0;
}