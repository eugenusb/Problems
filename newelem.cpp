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


par e[15];
par cnd[15];

tint x; tint y;

tint mcd(tint a, tint b)
{
    if(b == 0) return (a);
    return mcd(b, a % b);
}

par reducir(par p)
{
    tint num = p.F; tint den = p.S;

    if(num == 0) return mp(0,1);

    tint d = mcd(num, den);

    return mp(num/d, den/d);
}

bool rac_orden(par p, par q)
{
    tint det = p.F * q.S - p.S * q.F;

    return (det < 0);
}

bool orden(par p, par q)
{
    tint v1 = p.F * x + p.S * y;
    tint v2 = q.F * x + q.S * y;

    return (v1 < v2);
}

bool check(int n)
{
    forn(i,n-1)
    {
        tint v1 = cnd[i].F * x + cnd[i].S * y;
        tint v2 = cnd[i+1].F * x + cnd[i+1].S * y;

        if(v1 == v2) return (false);
        if(cnd[i] != e[i]) return (false);
    }

    return (true);
}

int main()
{
	int t,n; cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n;
        forn(i,n)
        {
            cin >> e[i].F >> e[i].S;
            cnd[i] = e[i];
        }
        
        set< par > ye;

        forn(i,n)
        {
            forn(j,i)
            {
                tint cx = e[i].F - e[j].F;
                tint cy = e[j].S - e[i].S;

                if(cx * cy > 0)
                {
                    par cn = reducir(mp(abs(cx), abs(cy)));
                    //cout << " orden " << cnd.F << " " << cnd.S << endl; 
                    ye.insert(cn);
                }
            }
        }

        vector<par> ordenado;

        fora(el,ye)
        {
            ordenado.pb(mp(el.S,el.F));            
        }

        sort(ordenado.begin(), ordenado.end(), rac_orden);

        //fora(el,ordenado) cout << el.F << " " << el.S << endl;        

        int m = ordenado.size();
        par ans;
        bool poss = false;

        forn(i,m-1)
        {
            tint a = ordenado[i].F; tint b = ordenado[i].S;
            tint c = ordenado[i+1].F; tint d = ordenado[i+1].S;

            y = (b + a) / a;
            x = 1;

            sort(cnd,cnd+n,orden);

            if(check(n))
            {
                if(poss)
                {
                    ans = min(ans, mp(x,y));
                }
                else
                {
                    ans = mp(x,y);
                    poss = true;
                }
            }
        }

        //check below ordenado[0]
        if(m and ordenado[0].S)
        {
            x = (ordenado[0].F + ordenado[0].S) / ordenado[0].S;
            y = (ordenado[0].S * x - ordenado[0].F) / ordenado[0].F;

            if(x >= 0 and y >= 0)
            {
                sort(cnd,cnd+n,orden);
                if(check(n))
                {
                    if(poss)
                    {
                        ans = min(ans, mp(x,y));
                    }
                    else
                    {
                        ans = mp(x,y);
                        poss = true;
                    }
                }
            }
        }

        // check (1,0)
        x = 1; y = 0;
        sort(cnd,cnd+n,orden);
        if(check(n))
        {
            if(poss)
            {
                ans = min(ans, mp(x,y));
            }
            else
            {
                ans = mp(x,y);
                poss = true;
            }
        }

        // check (0,1)
        x = 1; y = (m > 0) ? (ordenado[m-1].S + ordenado[m-1].F) / ordenado[m-1].F : 1;
        sort(cnd,cnd+n,orden);
        if(check(n))
        {
            if(poss)
            {
                ans = min(ans, mp(x,y));
            }
            else
            {
                ans = mp(x,y);
                poss = true;
            }
        }

        if(poss)
            cout << "Case #" << caso << ": " << ans.F << " " << ans.S << endl;
        else
            cout << "Case #" << caso << ": IMPOSSIBLE" << endl;

    }

	return 0;
}