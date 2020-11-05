#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

string s[15];

int main()
{
	int t; cin >> t;
	int n,m;
	forn(caso, t)
	{
		cin >> n >> m;

		forn(i,n) cin >> s[i];
		string ans = "-1";

		forn(i,m)
		{
			char prev = s[0][i];
			bool ready = false;
			for(int c = 'a'; c <= 'z'; c++)
			{
				s[0][i] = c;
				bool ok = true;
				forsn(j,1,n)
				{
					int diff = 0;
					forn(k,m)
					{
						if(s[0][k] != s[j][k]) diff++;
						if(diff > 1)
						{
							ok = false;
							break;
						}
					}
				}
				if(ok)
				{
					ans = s[0];
					//cout << i << " " << ans << endl;
					ready = true;
					break;
				}
			}
			if(ready) break;
			s[0][i] = prev;
		}

		cout << ans << endl;
	}

	return 0;
}