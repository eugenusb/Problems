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
 
 
string ques[100100];
tint pot2[100100];
const tint MOD = (tint)(1e9+7);

int main()
{
	int t; cin >> t;
	int n,m;

	pot2[0] = 1;
	forsn(i,1,100100)
	{
		pot2[i] = (2ll * pot2[i-1]) % MOD;
	}
	
	forsn(caso, 1, t+1)
	{
		cin >> n >> m;
		forn(i,n) cin >> ques[i];

		vector< par > cant(1<<m);
		forn(mask,1<<m)		
		{
			int in = 0;
			forn(j,1<<m)
			{
				if(mask & (1<<j)) in++;
			}
			cant[mask] = mp(in, mask);
		}

		sort(cant.begin(), cant.end());

		vector<int> bad(1<<m,0);
		vector<int> real_bad(1<<m,0);

		forn(i,n)
		{
			int code = 0;
			forn(j,m)
			{
				if(ques[i][j] == 'N')
					code += (1<<j);
			}
			bad[code]++;
		}

		for(int mask = (1<<m)-1; mask >= 0; mask--)
		{
			int tot = cant[mask].F;
			int cur_mask = cant[mask].S;
			
			forn(submask, 1<<tot)
			{
				int j = 0;
				int subset = 0;
				forn(i,m)
				{
					if(cur_mask & (1<<i))
					{
						if(submask & (1<<j))
							subset += (1<<i);
						j++;
					}
				}
				real_bad[subset] += bad[cur_mask];
			}
		}

		tint ans = 0;

		forsn(mask,1,1<<m)
		{
			tint cur = (pot2[n] - pot2[real_bad[mask]]) % MOD;
			forn(i,m)
			{
				if(mask & (1<<i)) cout << 1;
				else cout << 0;
			}
			cout << " : " << cur << endl;
			if(cur < 0) cur += MOD;
			ans ^= cur;
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}
