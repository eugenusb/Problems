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
#define EPS 1e-6

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

tint h[100100];
tint hg[100100];
tint decr[100100];
tint cre[100100];

int decode(string num)
{
	int sign = 1;
	int n = num.size();
	int st = 0;
	if(num[0] == '-')
	{
		sign = -1;
		st++;
		n--;
	}

	int ans = 0;

	if(n == 3)
	{
		ans = 10 * ((int)(num[st] - '0')) + (int)(num[st+2] - '0');
	}
	else
	{
		//n == 4
		ans = 100 * ((int)(num[st] - '0')) + 10 * ( (int)(num[st+1] - '0') ) + (int)(num[st+3] - '0');	
	}

	ans *= sign;

	return (ans);
}

int main()
{
	int n, k; string gg;
	cin >> n >> k;

	forn(i,n+1) cin >> h[i];

	cout.setf(ios::fixed | ios::showpoint);
   	cout.precision(12);

	forn(j,k)
	{
		cin >> gg;

		int g = decode(gg);

		//cout << g << endl;

		forn(i,n+1) hg[i] = h[i] - g * i;

		decr[n] = hg[n];
		for(int i = (n-1); i >= 0; i--) decr[i] = max(h[i] - g * i, decr[i+1]);
		
		double best = -1;

		// empieza en un km

		for(int i = (n-1); i >= 0; i--)
		{
			// busco el primer j > i tal que decr[j] < h[i] - g * i
			tint cnd = hg[i];

			if(decr[n] >= cnd) best = max(best, (double)(n - i));
			else
			{
				//decr[n] < cnd

				int lo = i; int hi = n;

				while(hi - lo > 1)
				{
					int m = (hi + lo) / 2;

					if(decr[m] < cnd) hi = m;
					else lo = m;
				}
				double lon = lo - i;
				lon += (cnd - hg[lo]) / (hg[hi] - hg[lo] + .0);
				best = max(best, lon);				
			}
		}

		// termina en un km

		cre[0] = hg[0];
		forsn(i,1,n+1) cre[i] = min(hg[i], cre[i-1]);

		//forn(i,n+1) cout << cre[i] << endl;

		for(int i = 1; i <= n; i++)
		{
			// busco el primer j < i tal que cre[j] > h[i] - g * i
			tint cnd = hg[i];

			if(cre[0] <= cnd) best = max(best, (double)(i));
			else
			{
				//cre[0] > cnd

				int lo = 0; int hi = i;

				while(hi - lo > 1)
				{
					int m = (hi + lo) / 2;

					if(cre[m] > cnd) lo = m;
					else hi = m;
				}
				double lon = i - hi;
				lon += (cnd - hg[hi]) / (hg[lo] - hg[hi] + .0);
				best = max(best, lon);
				//if(best >= 0.0) cout << best << " " << lon << " " << i << " " << hi << endl;
			}
		}

		//if(g <= 0) best = n;

		if(best >= EPS)
			cout << best << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}