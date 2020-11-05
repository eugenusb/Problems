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

tint x[1010];

bool poss(tint st, int n, tint d)
{
	tint cur = st;

	forn(i,n)
	{
		tint q = (cur + x[i] - 1) / x[i];
		cur = x[i] * q;
	}

	return (cur <= d);
}

int main()
{
	int t,n;
	tint d;

	cin >> t;

    forsn(caso,1,t+1)
    {
    	cin >> n >> d;
    	forn(i,n) cin >> x[i];

    	tint lo = 0; tint hi = d+5ll;

    	while(hi - lo > 1)
    	{
    		tint med = (lo + hi) / 2;

    		if(poss(med, n, d))
    		{
    			lo = med;
    		}
    		else
    		{
    			hi = med;
    		}
    	}

        cout << "Case #" << caso << ": " << lo << endl;
    }
	return 0;
}