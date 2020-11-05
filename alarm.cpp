#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;


tint a[1000010];
tint s[1000010];
tint p[1000010];
const tint MOD = (tint)(1e9+7);

tint modexp(tint b, tint e)
{
    if(e == 0) return 1;
    if(e == 1) return (b % MOD);

    tint med = e / 2;
    tint ans = modexp(b, med);

    ans = (ans * ans) % MOD;

    if(e & 1) ans = (ans * b) % MOD;

    return (ans);
}

tint inv(tint x)
{
    if(x == 1) return 1;

    return (modexp(x,MOD-2));
}

int main()
{
	int t; cin >> t;
    int n,k;
    tint x1,y1,c,d,e1,e2,f;

    forsn(caso,1,t+1)
    {
        cin >> n >> k;

        cin >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;
        a[1] = (x1 + y1) % f;

        forsn(i,2,n+1)
        {
            tint xi = ( c * x1 + d * y1 + e1 ) % f;
            tint yi = ( d * x1 + c * y1 + e2 ) % f;
            a[i] = (xi + yi) % f;

            x1 = xi; y1 = yi;
        }

        p[1] = k;

        forsn(l,2,n+1)
        {
            tint lk = modexp(l,k+1);
            tint inve = inv(l-1);
            tint a = ( (lk - l) * inve ) % MOD;
            if(a < 0) a += MOD;
            p[l] = a;
        }

        s[n+1] = 0;

        for(int i = n; i >= 1; i--)
        {
            s[i] = ( s[i+1] + a[i] * (n+1-i) ) % MOD;
        }

        tint ans = 0;

        forsn(i,1,n+1)
        {
            ans = (ans + p[i] * s[i]) % MOD;
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}