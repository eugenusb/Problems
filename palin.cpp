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

int acum[30][100100];

int main()
{
	int t,n,q; string s;
    int l,r;

	cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n >> q; cin >> s;
        forn(i,30) acum[i][0] = 0;
        int ans = 0;

        forn(i,n)
        {
            int c = (int)(s[i] - 'A');

            forn(j,30)
            {
                acum[j][i+1] = acum[j][i];
                if(j == c) acum[j][i+1]++;
            }
        }

        forn(i,q)
        {
            cin >> l >> r;
            int tot = r - l + 1;
            int odd = 0;

            forn(j,30)
            {
                int cant = acum[j][r] - acum[j][l-1];
                if(cant & 1) odd++;
            }

            if(tot & 1)
            {
                if(odd == 1) ans++;
            }
            else
            {
                if(odd == 0) ans++;
            }
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }
    
	return 0;
}