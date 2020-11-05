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

int main()
{
	int t;
	cin >> t;
	int w,h,l,u,r,d;

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(10);

    forsn(caso,1,t+1)
    {
    	cin >> w >> h >> l >> u >> r >> d;
    	double ans = 0;
        vector<double> pr;
        
    	if(l > 1 and h > d)
    	{
    		double prob = -(d-1)*log(2);
    		//ans += prob * 0.5;
    		pr.pb(prob - log(2));
    		forsn(k,1,l-1)
    		{
    			prob += log( (d - 1 + k) / (2.0*k + 0.0) );
    			//prob -= k * pow(0.5, d + k);
    			//ans += prob * 0.5;
    			pr.pb(prob - log(2));
    		}
    		//cout << ans << endl;
    	}
    	if(u > 1 and w > r)
    	{
    		double prob = -(r-1)*log(2);
    		//ans += prob * 0.5;
    		pr.pb(prob - log(2));
    		forsn(k,1,u-1)
    		{
    			prob += log( (r - 1 + k) / (2.0*k + 0.0) );
    			//prob -= k * pow(0.5, r + k);
    			//ans += prob * 0.5;
    			pr.pb(prob - log(2));
    		}
    		//cout << ans << endl;
    	}
        sort(pr.begin(), pr.end());
        forn(i,pr.size()) ans += exp(pr[i]);
        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}