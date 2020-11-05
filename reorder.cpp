#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sq(x) (x) * (x)
#define f first
#define s second

using namespace std;
typedef long long int tint;
typedef pair<int,int> par;

tint a[100100];
vector<int> b;

int main()
{
	int t,n;
	cin >> t;

	forn(caso,t)
	{
		cin >> n; 
		forn(i,n) cin >> a[i];

		sort(a,a+n);

		forn(i,n/2)
		{
			b.pb(a[n-1-i]);
			b.pb(a[i]);
		}
		if(n & 1) b.pb(a[n/2]);
		reverse(b.begin(), b.end());
		forn(i,n)
		{
			cout << b[i];
			if(i < (n-1) ) cout << " ";
			else cout << endl;
		}
	}

	return 0;
}