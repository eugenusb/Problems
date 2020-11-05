#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;

tint L[400100];
tint R[400100];

int main()
{
	int t; cin >> t;    
    int n,q;
    tint x1,x2,a,b,c,m;

    forsn(caso,1,t+1)
    {
        cin >> n >> q;

        cin >> x1 >> x2 >> a >> b >> c >> m;
        L[0] = x1; L[1] = x2;

        forsn(i,2,n)
        {
            tint x = (a * x2 + b * x1 + c) % m;
            L[i] = x;
            x1 = x2; x2 = x;
        }

        cin >> x1 >> x2 >> a >> b >> c >> m;
        R[0] = x1; R[1] = x2;

        forsn(i,2,n)
        {
            tint x = (a * x2 + b * x1 + c) % m;
            R[i] = x;
            x1 = x2; x2 = x;
        }
        vector< pair<int,bool> > inter;
        forn(i,n)
        {
            inter.pb(mp(min(L[i],R[i])+1,0));
            inter.pb(mp(max(L[i],R[i])+1,1));
        }

        sort(inter.begin(), inter.end());

        vector< par > qu;

        cin >> x1 >> x2 >> a >> b >> c >> m;
        qu.pb(mp(x1+1,1)); qu.pb(mp(x2+1,2));

        forsn(i,2,q)
        {
            tint x = (a * x2 + b * x1 + c) % m;
            qu.pb(mp(x+1,i+1));
            x1 = x2; x2 = x;
        }

        sort(qu.begin(), qu.end());

        tint ans = 0;
        int index = 0;
        tint cur = 0;
        tint open = 0;
        tint prev = inter[2*n-1].F;
        int i = 2*n-1;

        while(i >= 0 and index < q)
        {
            pair<int, bool > p = inter[i];
            int ex = p.F; bool op = p.S;
            //cout << ex << " " << op << " " << open << " " << prev << " " << cur << endl;
            //cout << index << " " << qu[index].F << " " << qu[index].S << endl;

            if(op)
            {
                tint pcur = cur;
                cur += (prev - ex) * open;
                while(index >= 0 and cur >= qu[index].F)
                {
                    if(cur == qu[index].F)
                    {
                        ans += (ex * qu[index].S);
                    }
                    else
                    {
                        // cur > qu[index].F

                        tint miss = qu[index].F - pcur;
                        miss = (miss + open - 1) / open;
                        tint ansi = (prev + 1 - miss);
                        ans += (ansi * qu[index].S);
                    }
                    index++;
                }
                while(inter[i].F == ex and inter[i].S)
                {
                    open++;
                    i--;
                }
                prev = ex;
            }
            else
            {
                tint pcur = cur;
                cur += (prev - ex) * open;

                while(index < q and cur >= qu[index].F)
                {
                    if(cur == qu[index].F)
                    {
                        ans += (ex * qu[index].S);
                    }
                    else
                    {
                        // cur > qu[index].F

                        tint miss = qu[index].F - pcur;
                        miss = (miss + open - 1) / open;
                        tint ansi = (prev + 1 - miss);
                        ans += (ansi * qu[index].S);
                    }
                    index++;
                }
                while(inter[i].F == ex and !inter[i].S)
                {
                    open--;
                    i--;
                    cur++;
                    while(index < q and cur == qu[index].F)
                    {
                        ans += (ex * qu[index].S);
                        index++;
                    }
                }
                prev = ex;
            }
            //cout << ex << " " << op << " " << open << " " << prev << " " << cur << endl;
            //cout << ans << endl;
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}