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

int s[55];

int main()
{
	int t; cin >> t;
	int n;
	forn(caso,t)
	{
		cin >> n;

		forn(i,n) cin >> s[i];

		sort(s,s+n);

		int ans = 1010;
		forn(i,n-1)
		{
			ans = min(ans, s[i+1] - s[i]);
		}

		cout << ans << endl;
	}

	return 0;
}