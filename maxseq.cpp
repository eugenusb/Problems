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
typedef pair<int,int> par;

tint b[200100];
tint a[200100];

int main()
{
	int n; cin >> n;
	forn(i,n) scanf("%lld",&b[i+1]);

	tint maxi = 0;

	forsn(i,1,n+1)
	{
		a[i] = b[i] + maxi;
		//cout << i << " " << b[i] << " " << maxi << endl;
		maxi = max(maxi, a[i]);
	}

	forsn(i,1,n) printf("%lld ",a[i]);
	cout << a[n] << endl;

	return 0;
}