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

int dp[100100][2];

int main()
{
	string s; getline(cin,s);
	int n = (int)(s.size());

	if('a' <= s[n-1] and s[n-1] <= 'z')
	{
		dp[n-1][0] = 1;
		dp[n-1][1] = 2;
	}
	else
	{
		if('A' <= s[n-1] and s[n-1] <= 'Z')
		{
			dp[n-1][0] = 2;
			dp[n-1][1] = 1;
		}
		else
		{
			dp[n-1][0] = 1;
			dp[n-1][1] = 1;
		}
	}

	for(int i = (n-2); i >= 0; i--)
	{
		if('a' <= s[i] and s[i] <= 'z')
		{
			dp[i][0] = 1 + dp[i+1][0];
			dp[i][1] = min(2+dp[i+1][1], 3+dp[i+1][0]);
		}
		else
		{
			if('A' <= s[i] and s[i] <= 'Z')
			{
				dp[i][0] = min(2+dp[i+1][0], 3+dp[i+1][1]);
				dp[i][1] = 1 + dp[i+1][1];
			}			
			else
			{
				dp[i][0] = 1 + dp[i+1][0];
				dp[i][1] = 1 + dp[i+1][1];
			}
		}
	}

	cout << dp[0][0] << endl;

	return 0;
}