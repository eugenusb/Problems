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

int a[110];

int main()
{
	int t; cin >> t;
	int n,k;
    forsn(caso,1,t+1)
    {
    	cin >> n >> k;
    	forn(i,n) cin >> a[i];

    	int ans = 0;
    	int bad = 0;
    	forn(i,n-1)
    	{
    		if(a[i] != a[i+1]) bad++;
    	}
    	//cout << bad << endl;
    	forsn(i,1,n-1)
    	{
    		if(a[i] == a[i-1]) continue;
    		if(a[i] == a[i+1]) continue;

    		if(a[i-1] == a[i+1])
    		{
    			ans++;
    			bad -= 2;
    			a[i] = a[i-1];
    		}

    		if(bad <= k) break;
    	}
    	//cout << ans << " " << bad << endl;
    	if(bad > k) ans += (bad - k);

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}