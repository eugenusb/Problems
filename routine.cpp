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

int m[100100];

bool poss(int x, int n, int k)
{
    int sp = 0;

    forn(i,n-1)
    {
        int d = m[i+1] - m[i];
        int need = (d + x - 1) / x;
        need--;
        sp += need;
    }

    return (sp <= k);
}

int main()
{
    int t;
    int n,k;
    
    cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n >> k;
        forn(i,n)
        {
            cin >> m[i];
        }

        int hi = (int)(1e9+5);
        int lo = 0;

        while(hi - lo > 1)
        {
            int med = (lo + hi) / 2;

            if(poss(med,n,k))
            {
                hi = med;
            }
            else
            {
                lo = med;
            }
        }

        cout << "Case #" << caso << ": " << hi << endl;
    }
    
    return 0;
}