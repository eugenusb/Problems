#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sq(x) (x) * (x)
#define f first
#define s second

using namespace std;
typedef long long int tint;
typedef pair<int,int> par;

tint a[100100];

int main()
{
	int t,n;
	cin >> t;

	forn(caso,t)
	{
		cin >> n; 
		forn(i,n) cin >> a[i];

		tint ans = 0;

		forn(i,n-1)
		{
			int d = a[i+1] - a[i];
			//cout << d << " " << a[i+1] << " " << a[i] << endl;
			if(d < 0)
			{
				d = -d;
				tint p = 0;

				while( (1ll<<p) <= d)
				{
					p++;
				}
				ans = max(ans,p);
				//cout << p << endl;
				a[i+1] = a[i];
			}
		}

		cout << ans << endl;
	}

	return 0;
}