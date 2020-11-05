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

int v[100100];

int main()
{
	int t; cin >> t;
    int n,q;
    int index, val;

    forsn(caso,1,t+1)
    {
    	set<int> ones;

    	cin >> n >> q;

    	int cant = 0;

    	forn(i,n)
    	{
    		cin >> v[i];
    		if(__builtin_popcount(v[i]) & 1)
    		{
    			//cout << i << " " << v[i] << endl;
    			ones.insert(i);
    			cant++;
    		}
    	}
    	
    	vector<int> ans;

    	forn(i,q)
    	{
    		cin >> index >> val;
    		if(__builtin_popcount(v[index]) & 1)
    		{
    			//cout << index << " " << v[index] << endl;
    			cant--;
    			ones.erase(index);
    		}
    		v[index] = val;
    		if(__builtin_popcount(v[index]) & 1)
    		{
    			cant++;
    			ones.insert(index);
    		}

    		if(cant & 1)
    		{
    			set<int>::iterator it;
    			set<int>::reverse_iterator rit;
    			int le = *ones.begin();
    			int ri = *ones.rbegin();

    			//cout << "LEFT AND RIGHT " << le << " " << ri << endl;

    			ans.pb(max(n-1-le,ri));
    		}
    		else
    		{
    			ans.pb(n);
    		}
    	}

        cout << "Case #" << caso << ": ";
        forn(i,q) cout << ans[i] << " ";
        cout << endl;
    }
	return 0;
}