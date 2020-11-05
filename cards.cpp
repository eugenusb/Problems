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

tint b[110];
tint r[110];
bool used[110];
vector< par > cnds[110];

int main()
{
	int t; cin >> t;
    int n;

    forsn(caso,1,t+1)
    {
        cin >> n;

        forn(i,n)
        {
            cin >> r[i];
            used[i] = false;
        }
        forn(i,n)
        {
            cin >> b[i];
            cnds[i].clear();
        }

        tint ans = 0;

        forn(i,n)
        {
            forn(j,i)
            {
                tint cnd = min(b[i] ^ r[j], r[i] ^ b[j]);
                cnds[i].pb(mp(cnd,j));
                cnds[j].pb(mp(cnd,i));
            }
        }

        forn(i,n) sort(cnds[i].begin(), cnds[i].end());
        /*
        forn(i,n)
        {
            fora(el, cnds[i])
            {
                cout << "(" <<  el.F << " " << el.S << ") ";
            }
            cout << endl;
        }
        */
        forn(iter,n-1)
        {
            vector< par > active;
            forn(i,n)
            {
                if(!used[i]) active.pb(mp(i,0));
            }
            int j = 0;
            while(active.size() > 1 and j < (n - 1 - iter))
            {
                tint cur = -1;
                fora(el, active)
                {
                    int index = el.F; int st = el.S;
                    while(used[cnds[index][st].S]) st++;
                    tint loc = cnds[index][st].F;
                    if(cur == -1) cur = loc;
                    else
                    {
                        if(j) cur = max(cur,loc);
                        else cur = min(cur,loc);
                    }
                }
                vector< par > aux_active;
                fora(el, active)
                {
                    int index = el.F; int st = el.S;                    
                    while(used[cnds[index][st].S]) st++;
                    if(cur == cnds[index][st].F)
                    {
                        aux_active.pb(mp(index,st+1));
                    }
                }
                active = aux_active;
                /*
                cout << cur << " " << j << " : " << endl;
                fora(el, active)
                {
                    cout << el.F << " ";
                }
                cout << endl;
                */
                j++;
            }

            par p = active[0];
            used[p.F] = true;
            fora(el, cnds[p.F])
            {
                if(!used[el.S])
                {
                    ans += el.F;
                    break;
                }
            }
            //cout << ans << " " << p.F << endl;
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}