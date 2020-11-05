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

tint p[10010];

bool can(int n, int c, tint totlim)
{
	int used = 1;
	int acum = 0;

	forn(i,n)
	{
		if(acum + p[i] <= totlim)
		{
			acum += p[i];
		}
		else
		{
			acum = p[i];
			used++;
			if(p[i] > totlim)
			{
				return (false);
			}
		}
	}

	bool ans = (used <= c);

	return (ans);
}

int main()
{
	int n,c,t;
	cin >> n >> c >> t;

	forn(i,n) cin >> p[i];

	tint hi = (int)(1e9) + 10;
	tint lo = 0;

	while(hi - lo > 1)
	{
		tint m = (hi + lo) / 2;

		if(can(n, c, m * t))
		{
			hi = m;
		}
		else
		{
			lo = m;
		}
	}

	cout << ans << endl;

	return 0;
}