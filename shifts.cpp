#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<tint, null_type,less_equal<tint>, rb_tree_tag,tree_order_statistics_node_update> 


tint a[25];
tint b[25];
map< par, ordered_set > dp;

void dfs(int d, int v, int n)
{
    if(d == n)
    {
        tint sum = 0;

        forn(i,n)
        {
            if(v & (1<<i)) sum += b[i];
        }
        dp[mp(n,v)].insert(sum);
        return;
    }
    forn(i,2)
    {
        dfs(d+1, v + i*(1 << d),n);
    }
    dp[mp(d,v)] = dp[mp(d+1,v)];
    forn(i,dp[mp(d+1,v+(1<<d))].size())
    {
        dp[mp(d,v)].insert(*dp[mp(d+1,v+(1<<d))].find_by_order(i));
    }

    cout << "par " << d << " " << v << endl;
    forn(i, dp[mp(d,v)].size())
    {
        cout << *dp[mp(d,v)].find_by_order(i) << " ";
    }
    cout << endl;

    return;
}

int main()
{
	int t; cin >> t;
    int n,h;
    forsn(caso,1,t+1)
    {
    	cin >> n >> h;
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];

        int ans = 0;

        dp.clear();
        dfs(0,0,n);
        int all = (1<<(n+1))-1;

        forn(mask,(1<<n))
        {
            tint at = 0; tint bt = 0;
            int in = 0;
            forn(i,n)
            {
                if(mask & (1<<i))
                {
                    in++;
                    at += a[i];
                }
                else
                {
                    bt += b[i];
                }
            }
            if(at >= h)
            {
                tint dif = (h - bt);
                par key = mp(in, mask);
                int good = (int)dp[key].size() - (int)(dp[key].order_of_key(dif+1));
                cout << mask << " " << at << " " << bt << " " << good << " " << dif << " " << key.F << " " << key.S << endl;
                ans += good;
            }            
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}