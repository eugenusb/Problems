#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define R real
#define I imag
#define sq(a) (a)*(a)
 
using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

int p[15];

bool is_special(int a)
{
	int aux = (a+1)^a;
	bool ans = (aux == (2*a + 1));

	return (ans);
}

int main()
{
	int g,n; cin >> g;

	forn(ca,g)
	{
		cin >> n;
		forn(i,n) cin >> p[i];

		int sg = 0;
		forn(i,n)
		{
			int q = (p[i] & 1) ? (p[i]+1) : (p[i]-1);
			sg = sg ^ q;
		}
		if(sg == 0) cout << "L" << endl;
		else cout << "W" << endl;
	}

	return 0;
}