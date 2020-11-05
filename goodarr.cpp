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

tint a[200100];
tint acum[200100];

unordered_map<tint, vector<int> > m;

int main()
{
	tint n;
	cin >> n;

	forn(i,n) cin >> a[i];

	acum[n-1] = a[n-1];
	m[0].pb(n);
	m[a[n-1]].pb(n-1);

	tint ans = n * (n + 1); ans /= 2;

	for(int i = (n-2); i >= 0; i--)
	{
		acum[i] = acum[i+1] + a[i];
		m[acum[i]].pb(i);
	}

	tint lim = n;

	for(int i = (n-1); i >= 0; i--)
	{
		int s = acum[i];
		
		if(m.find(s) != m.end())
		{
			if(m[s][0] == i) continue;
			// m[s][0] > i , m[s][hi] <= i

			int lo = 0; int hi = m[s].size() - 1;

			while(hi - lo > 1)
			{
				int med = (hi + lo) / 2;

				if(m[s][med] > i)
				{
					lo = med;
				}
				else
				{
					hi = med;
				}
			}
			//cout << s << " " << i << " " << m[s][lo] << " " << lim << endl;
			if(lim >= m[s][lo])
			{
				ans -= ((tint)(i+1))*((tint)(lim - m[s][lo] + 1));
				lim--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}