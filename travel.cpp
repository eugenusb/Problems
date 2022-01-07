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

const double EPS = (1e-9);
const double ERR = (1e-7);

bool cover(pair<double, double> p1, pair<double, double> p2, double n)
{
	if(p1 > p2) swap(p1,p2);

	if(p1.S < p2.F - EPS) return false;

	double lef = p1.F;
	double ri = max(p1.S, p2.S);

	double ans = (lef <= EPS) and (ri >= n - EPS);

	return (ans);
}

bool can(double tim, double p1, double v1, double p2, double v2, double n)
{
	double rec1 = v1 * tim;
	double rec2 = v2 * tim;

	vector< pair<double, double> > trav1;
	vector< pair<double, double> > trav2;

	// left, then right
	if(rec1 >= p1)
	{
		double rlim = max(rec1-p1,p1);
		rlim = min(rlim,n);
		trav1.pb(mp(0.0,rlim));
	}
	else
	{
		trav1.pb(mp(p1-rec1,p1));
	}

	if(rec2 >= p2)
	{
		double rlim = max(rec2-p2,p2);
		rlim = min(rlim,n);
		trav2.pb(mp(0.0,rlim));
	}
	else
	{
		trav2.pb(mp(p2-rec2,p2));
	}

	// right, then left
	if(rec1 >= n-p1)
	{
		double llim = min(n-(rec1-(n-p1)),p1);
		llim = max(llim,0.0);
		trav1.pb(mp(llim,n));
	}
	else
	{
		trav1.pb(mp(p1,p1+rec1));
	}

	if(rec2 >= n-p2)
	{
		double llim = min(n-(rec2-(n-p2)),p2);
		llim = max(llim,0.0);
		trav2.pb(mp(llim,n));
	}
	else
	{
		trav2.pb(mp(p2,p2+rec2));
	}

	// left some time, then right

	if(rec1 >= n-p1)
	{
		double llim = min(p1-(rec1-(n-p1))/2.0,p1);
		llim = max(llim,0.0);
		trav1.pb(mp(llim,n));
	}

	if(rec2 >= n-p2)
	{
		double llim = min(p2-(rec2-(n-p2))/2.0,p2);
		llim = max(llim,0.0);
		trav2.pb(mp(llim,n));
	}

	// right some time, then left

	if(rec1 >= p1)
	{
		double rlim = max((rec1-p1)/2.0+p1,p1);
		rlim = min(rlim,n);
		trav1.pb(mp(0.0,rlim));
	}

	if(rec2 >= p2)
	{
		double rlim = max((rec2-p2)/2.0+p2,p2);
		rlim = min(rlim,n);
		trav2.pb(mp(0.0,rlim));
	}

	fora(u,trav1)
	{
		fora(v,trav2)
		{
			//cout << tim << " " << u.F << " " << u.S << endl;
			//cout << tim << " " << v.F << " " << v.S << endl;
			if(cover(u,v,n)) return true;
		}
	}

	return false;
}

int main()
{
	int t; cin >> t;
	double n,p1,v1,p2,v2;
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(12);

	forn(caso,t)
	{
		cin >> n >> p1 >> v1 >> p2 >> v2;

		double hi = 10.0 * n / (min(v1,v2));
		double lo = 0.0;

		while(hi - lo > ERR)
		{
			double med = (hi + lo) / 2.0;

			if(can(med,p1,v1,p2,v2,n))
			{
				hi = med;
			}
			else lo = med;
		}

		cout << hi << endl;
	}

	return 0;
}