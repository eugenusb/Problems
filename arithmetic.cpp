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

int a[300100];
int dp[300100][2];
int dif[300100];

int solve(int n)
{
	forn(i,n)
	{
		dif[i] = a[i+1] - a[i];
		dp[i][0] = 0;
		dp[i][1] = 0;
	}

	dp[n-1][0] = 1;
	dp[n-1][1] = 1;
	dp[n-2][0] = 2;
	dp[n-2][1] = 2;

	if(dif[n-2] == dif[n-1])
	{
		dp[n-3][0] = 3;
		dp[n-3][1] = 3;
	}
	else
	{
		dp[n-3][0] = 2;
		dp[n-3][1] = 3;
	}
	

	for(int i = (n-4); i >= 0; i--)
	{
		if(dif[i] == dif[i+1])
		{
			dp[i][0] = 1 + dp[i+1][0];
			dp[i][1] = 1 + dp[i+1][1];
		}
		else
		{
			// dif[i] = a[i+1] - a[i], a[i+2] - a[i+1] != dif[i]
			dp[i][0] = 2;
			if(dif[i] * 2 == a[i+3] - a[i+1])
			{
				dp[i][1] = 3 + dp[i+3][0];
			}
			else
			{
				dp[i][1] = 3;
			}
		}
	}

	int ans = 1;
	forn(i,n-1)
	{
		forn(com,2)
		{
			cout << i << ": " << dp[i][com] << " ";
			ans = max(ans, dp[i][com]);
		}
		cout << endl;
	}

	return (ans);
}

int main()
{
	int t; cin >> t;
	int n;
	forsn(caso,1,t+1)
	{
		cin >> n;
		forn(i,n) cin >> a[i];
		int ans;

		if(n > 2)
		{
			ans = solve(n);
			reverse(a,a+n);
			ans = max(ans, solve(n));
		}
		else
		{
			ans = 2;
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}