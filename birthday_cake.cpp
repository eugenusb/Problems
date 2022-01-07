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
	int t; tint r,c,k;
	tint r1,c1,r2,c2;

	cin >> t;

	forsn(caso, 1, t+1)	
	{
		cin >> r >> c >> k;
		cin >> r1 >> c1 >> r2 >> c2;

		tint alto = r2 - r1 + 1;
		tint ancho = c2 - c1 + 1;

		tint ans = ((ancho + k - 1)/k) * (alto-1) + ((alto + k - 1)/k) * (ancho-1);

		if(r1 > 1)
			ans += (ancho+k-1)/k;
		if(r2 < r)
			ans += (ancho+k-1)/k;
		if(c1 > 1)
			ans += (alto+k-1)/k;
		if(c2 < c)
			ans += (alto+k-1)/k;

		tint ans1 = ans - (alto+k-1)/k + min( (r2+k-1)/k, (r-r1+k)/k);
		tint ans2 = ans - (ancho+k-1)/k + min( (c2+k-1)/k, (c-c1+k)/k);
		
		ans = min(ans1, ans2);

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}