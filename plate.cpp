#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

int a[55][40];
int pref[55][40];
int dp[55][30*50+10];

int main()
{
    int t;
    int n,k,p,v;
    
    cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n >> k >> p;
        forn(i,n)
        {
            pref[i][0] = 0;
            forn(j,k)
            {
                cin >> a[i][j];
                pref[i][j+1] = pref[i][j] + a[i][j];
            }
        }

        forn(i,n) forn(j,p+1) dp[i][j] = -1;
        forn(i,k+1) dp[0][i] = pref[0][i];

        forsn(i,1,n)
        {
            forn(j,p+1)
            {
                forn(l,min(k+1,j+1))
                {
                    if(dp[i-1][j-l] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-l] + pref[i][l]);
                }
            }
        }

        cout << "Case #" << caso << ": " << dp[n-1][p] << endl;

    }
    return 0;
}