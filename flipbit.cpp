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
	string a,b;
	int n; 
	forn(caso, t)
	{
		cin >> n;
		cin >> a >> b;

		int a_ones = 0;
		int a_zeros = 0;

		forn(i,n)
		{
			if(a[i] == '1') a_ones++;
			else a_zeros++;
		}
		bool ok = true;
		int i = (n-1);
		bool swit = false;

		while(i >= 0)
		{
			if(swit)
			{
				if(a[i] == b[i])
				{
					if(a_ones != a_zeros)
					{
						ok = false;
						break;
					}
					while(i >= 0 and a[i] == b[i])
					{
						if(a[i] == '1') a_ones--;
						else a_zeros--;
						i--;
					}
					swit = !swit;
				}
				else
				{
					if(a[i] == '1') a_ones--;
					else a_zeros--;
					i--;
				}
			}
			else
			{
				if(a[i] != b[i])
				{
					if(a_ones != a_zeros)
					{
						ok = false;
						break;
					}
					while(i >= 0 and a[i] != b[i])
					{
						if(a[i] == '1') a_ones--;
						else a_zeros--;
						i--;
					}
					swit = !swit;
				}
				else
				{
					if(a[i] == '1') a_ones--;
					else a_zeros--;
					i--;
				}
			}			
		}
		string ans = ok? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}