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
	int t,u; cin >> t; 
	tint q; string r;

    forsn(caso,1,t+1)
    {
		cin >> u;
		map<char,int> cnt;
		set<char> let;

		forn(i,10000)
		{
			cin >> q >> r;
			
			if(cnt.find(r[0]) != cnt.end()) cnt[r[0]]++;
			else cnt[r[0]] = 1;

			for(auto c : r)
			{
				let.insert(c);
				if(cnt.find(c) == cnt.end())
				{
					cnt[c] = 0;
				}
			}			
		}
		
		vector< pair<int, char> > cod;

		for(auto elem : cnt)
		{
			//cout << elem.F << " " << elem.S << endl;
			cod.pb(mp(elem.S, elem.F));
		}
		sort(cod.begin(), cod.end());
		reverse(cod.begin(), cod.end());


		string ans = "==========";

		forsn(i,1,10+1)
		{
			ans[i % 10] = cod[(i + 9) % 10].S;
		}
        
        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}