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

tint E[100100];
tint R[100100];
tint acum[100100];

int main()
{
	int t,n;
	cin >> t;

	forsn(caso,1,t+1)
	{
		cin >> n;
		forn(i,n) cin >> E[i] >> R[i];
		acum[0] = 0;
		forn(i,n) acum[i+1] = E[i] + acum[i];

		priority_queue< par > pq;
		vector<bool> used(n,false);

		forn(i,n) pq.push({R[i],i});
		tint tot = acum[n];
		bool check = true;

		while(!pq.empty() and check)
		{
			par p = pq.top(); pq.pop();

			tint r = p.F; int ind = p.S;

			if(tot - E[ind] < r)
			{
				used[ind] = true;
				tot -= E[ind];
			}
			else check = false;
		}

		if(!check)
		{
			cout << "Case #" << caso << ": " << "INDEFINITELY" << endl;
		}
		else
		{
			tint ans = 0;
			forn(i,n) pq.push({R[i],i});
			tint tot = acum[n];

			while(!pq.empty())
			{
				par p = pq.top(); pq.pop();

				tint r = p.F; int ind = p.S;

				if(tot - E[ind] < r)
				{
					used[ind] = true;
					tot -= E[ind];
				}
				else check = false;
			}
		}
	}

	return 0;
}