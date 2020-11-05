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
	tint n; cin >> n;
	tint cnt = 0;
	tint nn = n;
	for(tint di = 2; di * di <= n; di++)
	{
		if(nn % di == 0)
		{
			int pot = 0;

			while(nn % di == 0)
			{
				nn /= di;
				pot++;
			}

			cnt++;
		}
	}
	if(nn > 1) cnt++;

	tint ans = (1ll<<cnt) - cnt - 1;

	if(cnt == 1) ans = 0;

	cout << ans << endl;

	return 0;
}