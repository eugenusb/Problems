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

int h[50100];
int l[50100];
int r[50100];

int main()
{
	int n; cin >> n;

	forn(i,n) cin >> h[i];

	l[0] = 1;
	forsn(i,1,n)
	{
		l[i] = min(l[i-1]+1,h[i]);
	}
	r[n-1] = 1;
	for(int i = (n-2); i >= 0; i--)
	{
		r[i] = min(r[i+1]+1,h[i]);
	}
	int ans = 0;

	forn(i,n)
	{
		int cnd = min(l[i],r[i]);
		ans = max(ans, cnd);
	}

	cout << ans << endl;

	return 0;
}