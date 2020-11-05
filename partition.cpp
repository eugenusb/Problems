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

int p[200100];

const tint MOD = 998244353;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k; cin >> n >> k;
	vector<tint> pos;
	forn(i,n)
	{
		scanf("%d",&p[i]);
		if(p[i] > n-k) pos.pb(i);
	}

	tint ans1 = (tint)(k) * (tint)(2*n-k+1); ans1 /= 2ll;

	tint ans2 = 1ll;

	forn(i,k-1)
	{
		ans2 *= (pos[i+1] - pos[i]);
		ans2 %= MOD;
	}

	cout << ans1 << " " << ans2 << endl;

	return 0;
}