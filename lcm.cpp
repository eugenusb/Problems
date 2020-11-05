#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

int a[200100];
bool primo[200100];
vector<int> primos;

void criba()
{
	int MAXN = 200001;
	forn(i,MAXN) primo[i] = true;

	primos.pb(2);

	for(int m = 3; m*m <= MAXN; m += 2)
	{
		if(primo[m])
		{
			primos.pb(m);
			for(int p = m*m; p <= MAXN; p += m)
			{
				primo[p] = false;
			}
		}
	}
}

int cnt[200100];
vector<int> pot[200100];

int main()
{
	int n; cin >> n;
	criba();
	forn(i,n) scanf("%d",&a[i]);

	tint ans = 1;
	int k = primos.size();
	/*
	cout << k << endl;
	fora(p, primos) cout << p << " ";
	cout << endl;
	*/
	set<int> extra;
	forn(i,n)
	{
		int m = a[i];

		forn(j,k)
		{
			int po = 0;
			while(m % primos[j] == 0)
			{
				po++;
				m /= primos[j];
			}

			if(po)
			{
				cnt[primos[j]]++;
				pot[primos[j]].pb(po);

				if(m == 1) break;
			}
		}
		if(m > 1)
		{
			cnt[m]++;
			pot[m].pb(1);
			extra.insert(m);
		}
	}

	forn(i,k)
	{		
		if(cnt[primos[i]] >= (n-1))
		{
			/*
			cout << primos[i] << " " << cnt[primos[i]] << endl;
			fora(po, pot[primos[i]]) cout << po << " ";
			cout << endl;
			*/
			sort(pot[primos[i]].begin(), pot[primos[i]].end());
			int po;
			if(pot[primos[i]].size() == 1)
			{
				po = pot[primos[i]][0];
			}
			else
			{
				if(cnt[primos[i]] == n)
					po = pot[primos[i]][1];
				else
					po = pot[primos[i]][0];
			}
			forn(j, po) ans *= (tint)primos[i];
		}
	}
	fora(p, extra)
	{
		if(cnt[p] >= (n-1))
		{			
			ans *= (tint)p;
		}
	}

	cout << ans << endl;

	return 0;
}