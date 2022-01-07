#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)
#define R real
#define I imag
#define F first
#define S second

using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

tint a[5*100010];
tint dif[5*100010];
tint mini[5*100010];


const int INF = (int)(1e9);

int calc(int ind, tint p3)
{
	if(mini[0] < p3) return 0;
	int lo = 0;
	int hi = ind-2;

	while(hi - lo > 1)
	{
		int m = (hi + lo) / 2;

		if(mini[m] < p3)
		{
			hi = m;
		}
		else lo = m;
	}

	return hi;
}

int main()
{
	int n; cin >> n;
	forn(i,n) cin >> a[i];
	sort(a,a+n);
	reverse(a,a+n);
	forn(i,n-1) dif[i] = a[i] - a[i+1];

	mini[0] = dif[0];

	forsn(i,1,n-1)
	{
		mini[i] = min(mini[i-1], dif[i]);
	}

	tint ans = -1;

	forsn(i,2,n-4)
	{
		tint p3 = a[i];
		//cout << i << " " << p3 << " " << mini[i-2] << endl;
		if(p3 <= mini[i-2]) continue;
 
		tint bronze = 0;
		int pos = calc(i,p3);		
		forsn(j,i+1,i+4+1) bronze += a[j];
		tint gold = a[pos];
		tint silver = a[pos+1]+p3;

		//cout << gold << " " << silver << " " << bronze << endl;
		//cout << pos << " " << i << endl;
		if(gold < silver and silver < bronze) ans = max(ans, gold + silver + bronze);
	}

	cout << ans << endl;	

	return 0;
}