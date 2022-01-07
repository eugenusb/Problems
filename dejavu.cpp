#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;

int main()
{
	int t; cin >> t;
	string s;
	
	forn(caso, t)
	{
		cin >> s;
		int n = (int)(s.size());
		int pos = -1;
		forn(i,n)
		{
			if(s[i] != 'a')
			{
				pos = i;
				break;
			}
		}

		if(pos == -1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			cout << s.insert(n-pos,"a") << endl;
		}		
	}

	return 0;
}