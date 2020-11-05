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

int t,n;
int a[100100];
int b[100100];
int uno[100100];
int menos[100100];

int main()
{
	cin >> t;
	forn(caso,t)
	{
		cin >> n;

		forn(i,n)
		{
			cin >> a[i];
			uno[i+1] = uno[i];
			menos[i+1] = menos[i];
			if(a[i] == 1) uno[i+1]++;
			if(a[i] == -1) menos[i+1]++;
		}
		forn(i,n) cin >> b[i];

		bool ok = true;
		forn(i,n)
		{
			if(a[i] == b[i]) continue;

			if(a[i] < b[i])
			{
				if(uno[i] == 0)
				{
					ok = false;
					break;
				}
			}
			else
			{
				if(menos[i] == 0)
				{
					ok = false;
					break;
				}
			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}