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

int a[55];

int main()
{
	int t; cin >> t;
	int n;

	forn(caso,t)
	{
		cin >> n;
		forn(i,n) cin >> a[i];

		sort(a,a+n);
		int odd = 0; int ev = 0;
		int cons = 0;

		forn(i,n)
		{
			if(a[i] & 1) odd++;
			else ev++;
			if(i < (n-1))
			{
				if(a[i] + 1 == a[i+1]) cons++;
			}
		}

		if(odd % 2 == 0 and ev % 2 == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			if(cons) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;
}