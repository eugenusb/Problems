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

int mul[100100];

int main()
{
	int t; cin >> t;
    int n,m,q,p,r;

    forsn(caso,1,t+1)
    {
        set<int> torn;
    	cin >> n >> m >> q;
        forn(i,m)
        {
            cin >> p;
            torn.insert(p);
        }
        mul[1] = n - m;

        forsn(d,2,n+1)
        {
            mul[d] = 0;
            int lim = n / d;
            forsn(k,1,lim+1)
            {
                int cnd = k * d;

                if(torn.find(cnd) == torn.end()) mul[d]++;
            }
        }

        tint ans = 0;

        forn(i,q)
        {
            cin >> r;
            ans += mul[r];
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}