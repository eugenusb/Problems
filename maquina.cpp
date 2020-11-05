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
    int a,b,c;
    cin >> a >> b >> c;
    int ans = min(2*a + 2*c, 2*b + 4*c);
    ans = min(ans, 4*a + 2*b);
    cout << ans << endl;
	return 0;
}