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
	string s;
	int n; tint d,c,m;

	forsn(caso,1,t+1)
	{
		cin >> n >> d >> c >> m;
		cin >> s;
		int fi = -1;

		forn(i,n)
		{
			if(s[i] == 'C')
			{
				if(c)
				{
					c--;
				}
				else
				{
					fi = i;
					break;
				}
			}
			else
			{
				//s[i] = 'D'
				if(d)
				{
					d--;
					c += m;
				}
				else
				{
					fi = i;
					break;
				}
			}
		}

		if(fi == -1) fi = n;
		bool ok = true;
		forsn(i,fi,n)
		{
			if(s[i] == 'D')
			{
				ok = false;
				break;
			}
		}

		cout << "Case #" << caso << ": ";
		if(ok)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}