#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define R real
#define I imag
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

bool enc[1100];
vector<int> luz[1100];

int main()
{
	int n,m; cin >> n >> m;
	int l,lam; cin >> l;
	int pr = l;
	forn(i,l)
	{
		cin >> lam;
		enc[lam] = true;
	}
	int k;
	forn(i,n)
	{
		cin >> k;
		forn(j,k)
		{
			cin >> lam;
			luz[i].pb(lam);
		}
	}

	int ans = -1;
	if(pr == 0) ans = 0;
	forn(ind,2*n)
	{
		int i = ind % n;

		fora(p, luz[i])
		{
			if(enc[p])
			{
				pr--;
				enc[p] = false;
			}
			else
			{
				pr++;
				enc[p] = true;
			}
		}

		if(pr == 0)
		{
			ans = (ind+1);
			break;
		}
	}

	cout << ans << endl;

	return 0;
}