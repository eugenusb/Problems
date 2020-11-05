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
int a[200010];
bool perm[200010];
bool revperm[200010];

int main()
{
	int t; cin >> t;

	forn(caso,t)
	{
		cin >> n;
		forn(i,n) cin >> a[i];

		vector<int> ans; int k;
		int mini = 20000000;
		int maxi = 0;
		set<int> seen;

		forn(i,n)
		{
			mini = min(mini, a[i]);
			maxi = max(maxi, a[i]);
			seen.insert(a[i]);

			if(mini == 1 and maxi == (i+1) and seen.size() == (i+1)) perm[i] = true;
			else perm[i] = false;
		}

		mini = 20000000;
		maxi = 0;
		seen.clear();

		for(int i = (n-1); i >= 0; i--)
		{
			int j = n - i;
			mini = min(mini, a[i]);
			maxi = max(maxi, a[i]);
			seen.insert(a[i]);

			if(mini == 1 and maxi == j and seen.size() == j) revperm[i] = true;
			else revperm[i] = false;
		}
		forn(i,n-1)
		{
			if(perm[i] and revperm[i+1]) ans.pb(i+1);
		}
		k = ans.size();
		cout << k << endl;
		forn(i,k)
		{
			int d = ans[i];
			cout << d << " " << (n - d) << endl;
		}
	}
	return 0;
}