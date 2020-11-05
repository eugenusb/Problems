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


tint p[100100];
tint h[100100];
tint bx[100100];
tint by[100100];

int main()
{
	int t; cin >> t;
    int n,k;
    tint x1,x2,a,b,c,m;

    forsn(caso,1,t+1)
    {
        cin >> n >> k;

        cin >> x1 >> x2 >> a >> b >> c >> m;
        p[0] = x1; p[1] = x2;

        forsn(i,2,n)
        {
            tint x = (a * x2 + b * x1 + c) % m + 1;
            p[i] = x; x1 = x2; x2 = x;
        }

        cin >> x1 >> x2 >> a >> b >> c >> m;
        h[0] = x1; h[1] = x2;

        forsn(i,2,n)
        {
            tint x = (a * x2 + b * x1 + c) % m + 1;
            h[i] = x; x1 = x2; x2 = x;
        }

        cin >> x1 >> x2 >> a >> b >> c >> m;
        bx[0] = x1; bx[1] = x2;

        forsn(i,2,k)
        {
            tint x = (a * x2 + b * x1 + c) % m + 1;
            bx[i] = x; x1 = x2; x2 = x;
        }

        cin >> x1 >> x2 >> a >> b >> c >> m;
        by[0] = x1; by[1] = x2;

        forsn(i,2,k)
        {
            tint x = (a * x2 + b * x1 + c) % m + 1;
            by[i] = x; x1 = x2; x2 = x;
        }

        vector< pair< par, int > > event;
        set< par > active;
        
        //cout << "torres" << endl;
        forn(i,n)
        {
            //cout << p[i] << " " << h[i] << endl;
            event.pb( mp( mp(p[i],h[i]), k) );
        }
        //cout << "globos" << endl;
        forn(i,k)
        {
            //cout << bx[i] << " " << by[i] << endl;
            event.pb( mp( mp(bx[i],by[i]), i) );   
        }
        
        sort(event.begin(), event.end());
        //cout << "left-right" << endl;

        // left to right

        tint xo; bool fir = false;
        set<int> hit;

        forn(i,n+k)
        {
            pair< par, int > cur = event[i];
            int index = cur.S;
            tint a = cur.F.F; tint b = cur.F.S;

            //cout << a << " " << b << " " << index << endl;

            if(index < k)
            {
                if(!fir)
                {
                    fir = true;
                    xo = a;
                    active.insert(mp(b,index));
                }
                else
                {
                    active.insert(mp(b - (a - xo), index));
                }
            }
            else
            {
                // tower
                if(fir)
                {
                    tint t = a - xo;
                    //cout << "tower " << b - t << endl;
                    set< par >::iterator lim = active.lower_bound(mp(b-t,index));
                    set< par >::iterator it;
                    for(it = active.begin(); it != lim; it++)
                    {
                        hit.insert(it->S);
                    }
                    active.erase(active.begin(), lim);
                }
            }
            /*
            fora(elem, active)
            {
                cout << elem.F << " " << elem.S << endl;
            }
            */
        }

        // right to left

        fir = false;
        active.clear();

        for(int i = (n+k)-1; i >= 0; i--)
        {
            pair< par, int > cur = event[i];
            int index = cur.S;
            tint a = cur.F.F; tint b = cur.F.S;

            if(index < k)
            {
                if(!fir)
                {
                    fir = true;
                    xo = a;
                    active.insert(mp(b,index));
                }
                else
                {
                    active.insert(mp(b - (xo - a), index));
                }
            }
            else
            {
                // tower
                if(fir)
                {
                    tint t = xo - a;
                    set< par >::iterator lim = active.lower_bound(mp(b-t,index));
                    set< par >::iterator it;
                    for(it = active.begin(); it != lim; it++)
                    {
                        hit.insert(it->S);
                    }
                    active.erase(active.begin(), lim);
                }                
            }
        }

        /*
        fora(e,hit)
        {
            cout << bx[e] << " " << by[e] << endl;
        }
        */
        int ans = (int)(hit.size());
        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}