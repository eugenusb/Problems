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


int main()
{
	int t; cin >> t;    
	int n; string s;

    forsn(caso,1,t+1)
    {
    	cin >> n;
    	cin >> s;

    	int sum = 0;
    	int ans = 0;
    	int m = (n+1)/2;

    	forn(i,m)
    	{
    		int c = (int)(s[i] - '0');
    		sum += c;
    	}
    	ans = max(ans,sum);

    	for(int i = m; i < n; i++)
    	{
    		int ant = (int)(s[i-m] - '0');
    		int prev = (int)(s[i] - '0');
    		sum -= ant;
    		sum += prev;
    		ans = max(ans, sum);
    	}

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}