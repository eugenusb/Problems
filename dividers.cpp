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
vector< par > divi;
tint ans = -1;

void bt(tint cur, int i, int n, tint a, tint b, tint c, tint d)
{
	if(i == n)
	{
		//cout << cur << endl;
		if(cur % a == 0 and cur % b != 0 and d % cur != 0)
		{
			if(ans == -1) ans = cur;
			else ans = min(ans, cur);
		}
		return;
	}
	else
	{
		int pot = divi[i].S;
		tint pri = divi[i].F;
		tint u = 1;

		forn(j,pot+1)
		{
			bt(cur * u, i+1, n, a, b, c, d);
			u *= pri;
		}
	}
}

int main()
{
	tint a,b,c,d;

	cin >> a >> b >> c >> d;	

	tint cc = c;

	for(tint di = 2; di * di <= c; di++)
	{
		if(cc % di == 0)
		{
			int pot = 0;

			while(cc % di == 0)
			{
				cc /= di;
				pot++;
			}

			divi.pb({di,pot});
		}
	}
	int n = (int)divi.size();
	bt(1,0,n,a,b,c,d);
	cout << ans << endl;

	return 0;
}