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
    tint n; int m;
    tint O,E,p;

    forsn(caso,1,t+1)
    {
        cin >> n >> m;

        tint ans = 0;
        tint tot = 0;

        priority_queue< par > pq;
        vector< pair< par, tint > > ev;

        forn(i,m)
        {
            cin >> O >> E >> p;
            ev.pb( mp(mp(O,0),p) );
            ev.pb( mp(mp(E,1),p) );
            tint dif = E - O;
            tint sum = ( (n - dif + 1) * dif) % MOD + ( (dif * (dif - 1)) / 2 ) % MOD;
            sum = (p * sum) % MOD;
            tot = (tot + sum) % MOD;
        }

        sort(ev.begin(), ev.end());

        fora(el, ev)
        {
            tint st = el.F.F; int out = el.F.S;
            tint cant = el.S;

            //cout << st << " " << cant << " " << out << endl;

            if(out)
            {
                bool ok = true;
                while(ok)
                {
                    par pp = pq.top(); pq.pop();
                    tint org = pp.F; tint c = pp.S;
                    //cout << org << " " << c << endl;
                    if(c >= cant)
                    {
                        c -= cant;                        
                        tint dif = st - org;                        
                        tint sum = ( (n - dif + 1) * dif) % MOD + ( (dif * (dif - 1)) / 2 ) % MOD;                        
                        sum = (cant * sum) % MOD;
                        ans = (ans + sum) % MOD;
                        //cout << dif << " " << (n - dif + 1) << " " << sum << " " << ans << endl;                        
                        if(c) pq.push(mp(org,c));
                        break;
                    }
                    else
                    {
                        tint dif = st - org;
                        tint sum = ( (n - dif + 1) * dif) % MOD + ( (dif * (dif - 1)) / 2 ) % MOD;
                        sum = (c * sum) % MOD;
                        ans = (ans + sum) % MOD;
                        cant -= c;
                    }
                }
            }
            else
            {
                pq.push(mp(st,cant));
            }
        }

        //cout << tot << " " << ans << endl;

        ans = (tot - ans + MOD) % MOD;

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}