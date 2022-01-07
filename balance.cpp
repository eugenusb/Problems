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
	int n;
	string s;

	forn(caso, t)
	{
		cin >> n;
		cin >> s;

		int zeros = 0;
		forn(i,n)
		{
			if(s[i] == '0') zeros++;
		}

		if(zeros & 1 or s[0] != '1' or s[n-1] != '1')
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			string a = "";
			string b = "";

			forn(i,n) a += "?";
			a[0] = '('; a[n-1] = ')';
			int op = 0;
			int cnt = 0;
			int used = 1;
			forn(i,n)
			{
				if(s[i] == '0')
				{
					if(cnt & 1) a[i] = ')';
					else
					{
						a[i] = '(';
						used++;
					}
					cnt++;
				}
			}

			int tot = n/2;
			forn(i,n)
			{
				if(a[i] == '(')
				{
					op++;
				}
				else
				{
					if(a[i] == ')') op--;
					else
					{
						// a[i] = '?'
						if(used < tot)
						{
							a[i] = '(';
							used++;
							op++;
						}
						else
						{
							a[i] = ')';
							op--;
						}
					}
				}
			}
			//cout << a << endl;
			assert(op == 0);
			b = a;
			forn(i,n)
			{
				if(s[i] == '0')
				{
					char c = (a[i] == '(') ? ')' : '(';
					b[i] = c;
				}
			}
			cout << a << endl;
			cout << b << endl;
		}
	}

	return 0;
}