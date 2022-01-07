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

typedef long long ll;

ll gcd(ll a, ll b){return a?gcd(b %a, a):b;}

ll mulmod (ll a, ll b, ll c) { //returns (a*b)%c, and minimize overfloor
	ll x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

ll expmod (ll b, ll e, ll m){//O(log b)
	if(!e) return 1;
	ll q= expmod(b,e/2,m); q=mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

bool es_primo_prob (ll n, int a)
{
	if (n == a) return true;
	ll s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;
	
	ll x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;
	
	forn (i, s-1){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}
		
bool rabin (ll n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	forn (j,9)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}

ll rho(ll n){
    if( (n & 1) == 0 ) return 2;
    ll x = 2 , y = 2 , d = 1;
    ll c = rand() % n + 1;
    while( d == 1 ){
        x = (mulmod( x , x , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = gcd( x - y , n );
        else d = gcd( y - x , n );
    }
    return d==n? rho(n):d;
}

vector<ll> prim;
void factRho (ll n)
{
	if (n == 1) return;
	if (rabin(n)){
		prim.pb(n);
		return;
	}
	ll factor = rho(n);
	factRho(factor);
	factRho(n/factor);
}

ll a,b,c,n;
const ll MOD = (ll)(1e9+7);

ll p(ll x)
{
	ll xx = sq(x);
	ll ans = a * xx + b * x + c;

	return (ans);
}

int main()
{
	
	cin >> a >> b >> c >> n;

	forn(i,n)
	{
		factRho(p(i));
	}

	ll ans = 1ll;

	sort(prim.begin(), prim.end());
	int pot = 0;
	ll prev = prim[0];
	prim.pb(-1);

	fora(q, prim)
	{
		if(q != prev and pot)
		{
			//cout << prev << " " << pot << endl;
			ll po = pot / 2;
			ll temp = expmod(prev, po, MOD);
			ans = (ans * temp) % MOD;
			pot = 1;
			prev = q;
		}
		else pot++;		
	}

	ans = (ans * ans) % MOD;

	cout << ans << endl;

	return 0;
}