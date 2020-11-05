#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;

int main()
{
	int t; cin >> t;
	int a,b;
	forn(caso,t)
	{
		cin >> a >> b;
		int l = 2 * (min(a,b));
		l = max(l, max(a,b));
		int ans = (l) * (l);

		cout << ans << endl;
	}

	return 0;
}