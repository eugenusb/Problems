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
typedef pair<int,int> par;

int main()
{
	int t; cin >> t;
	string s, ans;
	
	forsn(caso, 1, t+1)	
	{
		cin >> s;
		int n = (int)(s.size());

		vector<int> cnt(30,0);

		forn(i,n)
		{
			int c = (int)(s[i] - 'a');
			cnt[c]++;
		}

		bool ok = true;

		forn(i,30)
		{
			if(2 * cnt[i] > n) ok = false;
		}

		ans = "";

		if(!ok) ans = "IMPOSSIBLE";
		else
		{
			vector< par > info;

			forn(i,30) info.pb(mp(cnt[i], i));
			sort(info.begin(), info.end());
			reverse(info.begin(), info.end());

			string aux = "";

			forn(i,30)
			{
				par p = info[i];
				char let = (char)(p.S+'a');

				forn(j, p.F) aux += let;
			}
			int maxi = info[0].F;

			ans = aux.substr(maxi) + aux.substr(0, maxi);
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}