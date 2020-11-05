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

string pref[110];
bool use[110];

bool prefix(string a, string b)
{
	int A = a.size(); int B = b.size();

	if(B < A) return (false);

	forn(i,A)
	{
		if(a[i] != b[i]) return (false);
	}

	return (true);
}

int main()
{
	int t; cin >> t;
	int n,p;
    forsn(caso,1,t+1)
    {
    	cin >> n >> p;
    	forn(i,p)
    	{
    		cin >> pref[i];
    		use[i] = true;
    	}
    	sort(pref,pref+p);

    	forn(i,p)
    	{
    		forsn(j,i+1,p)
    		{
    			if(prefix(pref[i], pref[j]))
    			{
    				use[j] = false;
    			}
    		}
    	}

    	tint ans = (1ll << n);

    	forn(i,p)
    	{
    		if(use[i])
    		{
    			tint k = pref[i].size();
    			ans -= (1ll << (n - k));
    		}
    	}

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}