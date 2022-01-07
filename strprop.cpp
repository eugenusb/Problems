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

int len[200100];

int main()
{
	int t; cin >> t;
	int n;

	forsn(caso,1,t+1)
	{
		cin >> n;
		string s; cin >> s;

		len[0] = 1;

		forsn(i,1,n)
		{
			if(s[i-1] < s[i])
			{
				len[i] = 1 + len[i-1];
			}
			else len[i] = 1;
		}

		cout << "Case #" << caso << ": ";
		forn(i,n) cout << len[i] << " ";
		cout << endl;
	}

	return 0;
}