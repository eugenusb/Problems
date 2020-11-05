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

int h[110];

int main()
{
	int t,n;
	cin >> t;

    forsn(caso,1,t+1)
    {
        cin >> n;
        forn(i,n) cin >> h[i];

        int ans = 0;

        forsn(i,1,n-1)
        {
        	int a = h[i];

        	if(a > h[i-1] and a > h[i+1]) ans++;
        }
        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}