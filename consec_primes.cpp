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
tint range = 5e5;

vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);

    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}

int main()
{
	int t; cin >> t;
	tint z;

	forsn(caso,1,t+1)
	{
		cin >> z;

		tint r = (tint)(sqrt(z));
		tint lim_inf = max(2ll,r-range);
		tint lim_sup = r+range;
		vector<bool> isPrime = segmentedSieve(lim_inf, lim_sup);
		vector<tint> primos;

		forn(i,isPrime.size())
		{
			if(isPrime[i])
			{
				primos.pb(i+lim_inf);
			}
		}

		tint ans = -1;

		int cant_primes = (int)(primos.size());
		forn(i, cant_primes-1)
		{
			//cout << primos[i] << endl;
			tint cnd = primos[i] * primos[i+1];
			if(cnd <= z) ans = max(ans, cnd);
			else break;
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}