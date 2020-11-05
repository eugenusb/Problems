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

tint dp[55][100100];
const int MOD = (int)(1e9+7);

int main()
{
	int t,n,m; cin >> t >> n >> m;

	forsn(i,n,m+1) dp[1][i] = 1;

	forsn(i,2,t+1)
	{
		dp[i][n] = dp[i-1][n+1];
		dp[i][m] = dp[i-1][m-1];

		forsn(j,n+1,m)
		{
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		}
	}

	tint ans = 0;

	forsn(i,n,m+1) ans = (ans + dp[t][i]) % MOD;

	cout << ans << endl;

	return 0;
}