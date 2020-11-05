#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;


tint dp[210][110][110][2];
const tint MOD = (tint)(1e9+7);

int main()
{
	int t; cin >> t;    
    int N,M;
    forsn(caso,1,t+1)
    {
        cin >> N >> M;

        dp[0][0][0][0] = 1;
        dp[0][0][1][0] = 0;
        dp[0][0][1][1] = 0;
        dp[0][0][0][1] = 0;

        forsn(i,1,2*N+1)
        {
            forn(j,max(i/2, M)+1)
            {
                forn(k,min(M-j,i)+1)
                {
                    dp[i][j][k][0] = ( (dp[i-1][j][k][1] + dp[i-1][j][k][0]) * ((tint)(2*N - i + 1 - 2*(M-j) + k)) ) % MOD;
                    if(j)
                        dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j-1][k+1][0] * (k+1) + dp[i-1][j-1][k+1][1] * k) % MOD;
                    if(k)                    
                        dp[i][j][k][1] = ( (dp[i-1][j][k-1][0] + dp[i-1][j][k-1][1]) * ( (tint)(2*(M-j-k+1)) ) ) % MOD;

                    //cout << i << " " << j << " " << k << " " << 0 << " : " << dp[i][j][k][0] << endl;
                    //cout << i << " " << j << " " << k << " " << 1 << " : " << dp[i][j][k][1] << endl;
                }
            }
        }

        cout << "Case #" << caso << ": " << dp[2*N][M][0][0] << endl;
    }

	return 0;
}