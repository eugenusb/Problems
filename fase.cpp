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

int p[1010];

int main()
{
	int n,k;
	cin >> n; cin >> k;

	forn(i,n) cin >> p[i];
	sort(p,p+n);
	reverse(p,p+n);
	int ans = k;
	for(int i = k; i < n; i++)
	{
		if(p[i] == p[k-1]) ans++;
	}
	cout << ans << endl;
	 
	return 0;
}