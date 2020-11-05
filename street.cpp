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


#define MAXP 100000

bool criba[MAXP+5];
vector<int> primos;

void crearcriba()
{
    for(int p = 4; p <= MAXP; p += 2) criba[p] = true;

    for(tint p = 3; p <= MAXP; p += 2)
    {
        //cout << p << endl;
        if(!criba[p])
        {
            for(tint j = p * p; j <= MAXP; j += p)
            {
                //cout << j << endl;
                criba[j] = true;
            }
        }
    }
    //cout << "OK" << endl;
    forsn(i,2,MAXP+1)
    {
        if(!criba[i]) primos.pb(i);
    }
    //cout << primos.size() << endl;
}

bool esPrimo(int x)
{
    if(x <= MAXP) return (!criba[x]);

    int n = primos.size();
    forn(i,n)
    {
        if((x % primos[i]) == 0) return false;
    }
    return (true);
}
/*
int cant(int k)
{
    int np = primos.size();
    if(k >= primos[np-1]) return (np);
    if(k < primos[0]) return (0);
    // primos[0] <= k < primos[np-1];

    int hi = np-1; int lo = 0;

    while(hi - lo > 1)
    {
        int med = (hi + lo) / 2;

        if(primos[med] <= k)
        {
            lo = med;
        }
        else hi = med;
    }

    return (hi);
}


int solve(int r)
{
    int ans = cant(r);
    ans += (cant(r/4));
    int mit = r/2;

    ans += (mit+1) / 2;

    return (ans);
}
*/

int main()
{
	int t; cin >> t;
    int l,r;

    crearcriba();

    //cout << "criba lista" << endl;

    forsn(caso,1,t+1)
    {
        cin >> l >> r;

        int ans = 0;

        forsn(x,l,r+1)
        {
            if(x & 1)
            {
                if(esPrimo(x))
                {
                    ans++;
                    //cout << x << endl;
                }
            }
            else
            {
                int xx = x/2;

                if(xx & 1)
                {
                    ans++;
                    //cout << "doble impar " << x << endl;
                }
                else
                {
                    if(esPrimo(xx/2))
                    {
                        ans++;
                        //cout << "4 primo " << xx/2 << endl;
                    }
                }
            }
        }
        
        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}