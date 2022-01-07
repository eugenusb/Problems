#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)
#define R real
#define I imag
#define F first
#define S second

using namespace std;
 
typedef long long int tint;
typedef pair<tint,tint> par;

tint a[100010];
tint b[100010];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int n,m;

    forn(caso, t)
    {
    	cin >> n;
    	forn(i,n) cin >> a[i];
    	cin >> m;
    	forn(i,n) cin >> b[i];

    	if(n != m) cout << "NO" << endl;
    	else
    	{
    		if(n <= 1) cout << "YES" << endl;
    		else
    		{
    			// n >= 2
    			sort(a,a+n);
    			sort(b,b+n);

    			if(a[n-1] == a[0])
    			{
    				if(b[n-1] == b[0])
    				{
    					cout << "YES" << endl;
    				}
    				else
    				{
    					cout << "NO" << endl;
    				}
    				continue;
    			}

    			// x > 0
    			par x = {b[n-1]-b[0], a[n-1]-a[0]};
    			par y = {b[0]*x.S - a[0]*x.F, x.S};

    			bool ok_pos = true;
    			forn(i,n)
    			{
    				if(a[i] * x.F + y.F != b[i] * x.S)
    				{
    					ok_pos = false;
    					break;
    				}
    			}

    			ok_pos = ok_pos and (x.S * x.F > 0);

    			bool ok_sum = true;

    			tint cnst = b[0] - a[0];

    			forsn(i,1,n)
    			{
    				if(a[i] + cnst != b[i])
    				{
    					ok_sum = false;
    					break;
    				}
    			}

    			ok_pos = ok_pos or ok_sum;

    			// x < 0

    			reverse(a,a+n);

    			x = {b[n-1]-b[0], a[n-1]-a[0]};
    			y = {b[0]*x.S - a[0]*x.F, x.S};

    			bool ok_neg = true;
    			forn(i,n)
    			{
    				if(a[i] * x.F + y.F != b[i] * x.S)
    				{
    					ok_neg = false;
    					break;
    				}
    			}

    			ok_neg = ok_neg and (x.S * x.F < 0);

    			bool ok_sum_rev = true;

    			cnst = b[0] - a[0];

    			forsn(i,1,n)
    			{
    				if(a[i] + cnst != b[i])
    				{
    					ok_sum_rev = false;
    					break;
    				}
    			}

    			ok_neg = ok_neg or ok_sum_rev;

    			if(ok_pos or ok_neg)
    			{
    				cout << "YES" << endl;
    			}
    			else cout << "NO" << endl;
    		}
    	}
    }

	return 0;
}