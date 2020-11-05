#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define R real
#define I imag
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

int main()
{
	string s,t;
	cin >> s >> t;

	int n = (int)(s.size());
	int m = (int)(t.size());

	int ans = 0;
	forn(i,n-m+1)
	{
		bool is = true;
		forn(j,m)
		{
			if(t[j] == s[i+j])
			{
				is = false;
				break;
			}
		}
		if(is) ans++;
	}

	cout << ans << endl;

	return 0;
}