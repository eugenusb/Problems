#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;


par a[10100];

int main()
{
	int t,n,d; cin >> t; 
	tint u;

    forsn(caso,1,t+1)
    {
		cin >> n >> d;
		map<tint, vector< pair< par, int> > > info;

		forn(i,n)
		{
			cin >> u;
			a[i] = mp(u,i);
			forsn(c,2,d+1)
			{
				tint cnd = c * u;
				info[cnd].pb(mp(mp(c, u), i));
			}
		}

		sort(a, a + n);

		fora(elem, info)
		{
			sort(elem.S.begin(), elem.S.end());
		}

		int ans = d-1;

		int index = 0;

		while(index < n)
		{
			par cur = a[index];
			int tot = 0;
			while(index < n and a[index].F == cur.F)
			{
				index++;
				tot++;
			}
			int slice = tot;
			if(slice >= d) ans = 0;
			else
			{				
				int cuts = 0;
				set<int> used;
				if(info.find(cur.F) != info.end())
				{
					fora(elem, info[cur.F])
					{
						tint ca = elem.F.F;
						int j = elem.S;
						if(slice + ca <= d)
						{
							slice += ca;
							cuts += (ca - 1);
							used.insert(j);
						}
						else
						{
							int dif = d - slice;
							slice = d;
							cuts += dif;
							used.insert(j);
						}
						if(slice == d)
						{
							ans = min(ans, cuts);
							break;
						}
					}
				}

				if(slice < d)
				{
					forsn(j, index+1, n)
					{
						if(used.find(j) != used.end()) continue;
						tint q = (a[j].F) / a[index].F;
						if(slice + q <= d)
						{
							slice += q;
							cuts += q;
						}
						else
						{
							int dif = d - slice;
							slice = d;
							cuts += dif;
						}
						if(slice == d)
						{
							ans = min(ans, cuts);
							break;
						}
					}
				}
			}
		}

		fora(elem, info)
		{
			if(elem.S.size() == 1) continue;

			tint cut = elem.F;
			par repi = (elem.S[0]).F;
			par repj = (elem.S[1]).F;
			set<int> used;
			tint cj = repi.F; tint ai = repi.S;
			tint ci = repj.F; tint aj = repj.S;

			//cout << ci << " " << ai << " " << cj << " " << aj << " " << ai/(ci+0.0) << " " << aj/(cj+.0) << endl;
			//cout << "--------------------------------------------" << endl;
			
			int slice = 0; int cuts = 0;

			fora(p, elem.S)
			{
				tint ca = p.F.F;
				int index = p.S;

				//cout << ca << " " << p.F.S << " " << index << endl;

				if(slice + ca <= d)
				{
					used.insert(index);
					slice += ca;
					cuts += (ca - 1);
				}
				else
				{
					int dif = d - slice;
					slice = d;
					cuts += dif;
				}

				if(slice == d)
				{
					ans = min(ans, cuts);
					break;
				}
			}

			if(slice < d)
			{
				int lo = 0; int hi = (n-1);
				if(ai < ci * a[lo].F) break;
				if(ci * a[hi].F < ai) break;

				// c * a[lo].F <= ai <= c * a[n-1].F

				while(hi - lo > 1)
				{
					int med = (lo + hi) / 2;

					if(ai < ci * a[med].F)
					{
						hi = med;
					}
					else
					{
						lo = med;
					}
				}

				forsn(j,hi,n)
				{					
					if(used.find(j) == used.end())
					{
						tint q = (ci * a[j].F) / ai;
						if(slice + q <= d)
						{
							slice += q;
							cuts += q;
						}
						else
						{
							int dif = d - slice;
							slice = d;
							cuts += dif;
						}
					}
					if(slice == d) break;
				}

				if(slice == d) ans = min(ans, cuts);
			}
		}
		

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}