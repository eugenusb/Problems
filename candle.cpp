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
typedef complex<tint> punto;

punto candle[200100];

int orientation(punto a, punto b, punto c) 
{
	tint det = (b.I() - a.I()) * (c.R() - b.R()) - (b.R() - a.R()) * (c.I() - b.I());

	if (det == 0) return 0;
	return (det > 0) ? 1 : 2;
}

punto center;
vector< punto > convex;

bool compare(const punto a, const punto b)
{
	int o = orientation(center, a, b);
   	if (o == 0)
   	{
   		return (norm(a - center) <= norm(b - center));
   	}
	
	return (o == 2);
}

void chull(int n)
{
	tint mini = candle[0].I(); int mpos = 0;

	forsn(i,1,n)
	{
		if(candle[i].I() < mini)
		{
			mini = candle[i].I();
			mpos = i;
		}
		else
		{
			if(candle[i].I() == mini and candle[i].R() < candle[mpos].R())
				mpos = i;
		}
	}

	swap(candle[0], candle[mpos]);
	center = candle[0];

	sort(candle+1, candle+n, compare);

	int m = 1;

	forsn(i,1,n)
	{
		while(i < n-1 and orientation(center, candle[i], candle[i+1]) == 0)
			i++;

		candle[m] = candle[i]; 
		m++;
	}

	forn(j,3) convex.pb(candle[j]);

	forsn(i,3,m)
	{
		int k = convex.size();
		punto a = convex[k-1]; punto b = convex[k-2];
		while (orientation(b, a, candle[i]) != 2) 
        {
        	convex.pop_back();
        	k--;
        	a = b;
        	b = convex[k-2];
        }
      	convex.pb(candle[i]);
	}

	//fora(s, convex) cout << s << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(12);

	int n,r; cin >> n; cin >> r;
	tint a,b;

	forn(i,n)
	{
		cin >> a >> b;
		candle[i] = punto(a,b);
	}

	chull(n);

	double ans = 2*r + 10;
	int j = 2;

	int k = convex.size();

	forn(i,k)
	{
		punto base = convex[(i+1) % k] - convex[i];
		punto rot = base * punto(0,1);
		tint proy = 0;
		punto cnd = convex[j] - convex[i];
		tint dot = (conj(cnd) * rot).R();
		
		while(j != i and dot >= proy)
		{
			proy = dot;
			j++; j %= k;
			cnd = convex[j] - convex[i];
			dot = (conj(cnd) * rot).R();
		}
		j--; j %= k;
		if(j < 0) j += k;
		cnd = convex[j] - convex[i];
		double w = (conj(cnd) * rot).R() / sqrt(norm(rot));

		//cout << base << " " << cnd << " " << sqrt(norm(rot)) << " " << w << endl;

		ans = min(ans, w);
	}	

	cout << ans << endl;

	return 0;
}