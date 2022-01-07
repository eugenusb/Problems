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
	tint n; cin >> n;
	tint ones = 2ll * (n / 3ll);
	tint r = (n % 3);
	ones += r;

	tint ans = n * n - n - ones * (ones - 1ll);
	ans /= 2;

	cout << ans << endl;
	
	return 0;
}