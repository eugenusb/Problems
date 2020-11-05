#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

int a[200100];

int main()
{
	int t; cin >> t;
	int n,k;

    forsn(caso,1,t+1)
    {
		cin >> n >> k;

		int cant = 0;
		int ans = 0;
		forn(i,n) cin >> a[i];

		for(int i = n-1; i >= 0; i--)
		{
			if(a[i] == cant+1)
			{
				cant++;
			}
			else
			{
				cant = 0;
				if(a[i] == 1) cant++;
			}
			if(cant == k)
			{
				ans++;
				cant = 0;
			}
		}


        cout << "Case #" << caso << ": " << ans << endl;
    }

    return 0;
}