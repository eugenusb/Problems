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


int a[310];
int b[310];


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


int main()
{
	int t,n; cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n;

        forn(i,n) cin >> a[i] >> b[i];
        
        set< par > ye; ye.insert(mp(0,1));

        forn(i,n)
        {
            forn(j,i)
            {
                tint cx = a[i] - a[j];
                tint cy = b[j] - b[i];

                if(cx * cy > 0)
                {
                    par cnd = reducir(mp(abs(cx), abs(cy)));
                    //cout << " orden " << cnd.F << " " << cnd.S << endl; 
                    ye.insert(cnd);
                }
            }
        }

        int ans = (int)(ye.size());

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}