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

const tint MOD = 1000002013;

int main()
{
	int t; cin >> t;
    tint n, p;

    forsn(caso,1,t+1)
    {
        cin >> n >> p;

        tint a = 1;
        tint guar = 0;

        for(tint i = 1; i <= n; i++)
        {
            a += (1ll << (n-i));
            if(p < a)
            {
                break;
            }
            else
            {                
                guar += (1ll << (i));
            }
        }
        guar = min(guar, (1ll<<(n))-1ll);
        tint pot = n; tint j = 0;

        while(p < (1ll<<pot))
        {
            pot--;
            j++;
        }
        // p >= (1ll<< pot)
        tint best = (1ll<<n) - (1ll<<j);

        cout << "Case #" << caso << ": " << guar << " " << best << endl;
    }

	return 0;
}