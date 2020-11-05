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
typedef pair<int,int> par;


tint modexp(tint b, tint n, tint m)
{
    if(n == 0) return 1;
    if(n == 1) return (b % m);

    tint a = modexp(b,n/2,m);
    tint ans = (a * a) % m;

    if(n & 1)
    {
        ans = (ans * b) % m;
    }

    return (ans);
}

int main()
{
	int t; cin >> t;
    tint a,p,n;

    forsn(caso,1,t+1)
    {
        cin >> a >> n >> p;
        tint ans = a % p;

        forsn(i,2,n+1)
        {
            ans = modexp(ans, i, p);
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}