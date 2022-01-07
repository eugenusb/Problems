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

map<string, int> dic;
map<string, int> app;
map<string, int> code;

int main()
{
	int n; cin >> n;
	int a,b; int ans = 10010;

	forn(i,n)
	{
		cin >> a >> b;

		int cnd = b / a;
		ans = min(ans,cnd);
	}

	cout << ans << endl;

	return 0;
}