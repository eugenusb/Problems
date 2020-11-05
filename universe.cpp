#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

tint a[1010];

tint calc(int bit, tint m, int n, bool on)
{
    tint ans = 0;
    tint acum = 0;

    //cout << bit << " " << m << " " << on << endl;

    if(bit == 0)
    {
        if(on)
        {
            ans = 1;
            forn(i,n)
            {
                if(a[i] & 1) continue;
                acum += 1;
            }
            if(acum <= m) return (ans);
            else return (-1);
        }
        else
        {
            forn(i,n)
            {
                acum += (a[i] & 1);
            }
            if(acum <= m)
            {
                return (ans);
            }
            else return (-1);
        }

        return (-1);
    }

    if(on)
    {
        ans += (1ll << bit);
        forn(i,n)
        {
            if(a[i] & (1ll << bit)) continue;
            acum += (1ll << bit);
        }
        if(acum <= m)
        {
            tint partial = calc(bit-1,m-acum,n,true);
            if(partial != -1) return (ans + partial);
            else
            {
                partial = calc(bit-1,m-acum,n,false);
                if(partial != -1) return (ans + partial);
                else return (-1);
            }
        }
        else return (-1);
    }
    else
    {
        forn(i,n)
        {
            acum += (a[i] & (1ll << bit));
        }
        if(acum <= m)
        {
            tint partial = calc(bit-1,m-acum,n,true);
            if(partial != -1) return (ans + partial);
            else
            {
                partial = calc(bit-1,m-acum,n,false);
                if(partial != -1) return (ans + partial);
                else return (-1);
            }
        }
        else return (-1);
    }

    return (-1);
}


int main()
{
	int t; cin >> t;
    int n; tint m;

    forsn(caso,1,t+1)
    {
        cin >> n >> m;
        tint tot = 0;
        forn(i,n)
        {
            cin >> a[i];
            tot += a[i];
        }

        tint ans = -1;
        if(tot <= m) ans = 0;

        for(int b = 50; b >= 0; b--)
        {
            tint acum = 0;

            for(int bi = 50; bi > b; bi--)
            {
                forn(i,n)
                {
                    acum += (a[i] & (1ll<<bi));
                }
            }
            if(acum > m) continue;

            tint cnd = calc(b,m-acum,n,true);
            if(cnd != -1)
            {
                ans = cnd;
                break;
            }
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}