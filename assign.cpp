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
typedef pair<tint,tint> par;

par rese[300010];

int main()
{
	int n,m;
	int tot = 0;
	priority_queue<tint> machine;

	cin >> n >> m;
	forn(i,n)
	{
		cin >> rese[i].F >> rese[i].S;
		//rese[i].S = - rese[i].S;
	}
	sort(rese, rese + n);

	forn(i,n)
	{
		bool ok = false;
		tint a = rese[i].F; tint s = rese[i].S;

		while(!machine.empty())		
		{
			tint q = machine.top();
			q = -q;
			//cout << i << " " << q << endl;
			if(a < q) break;
			else
			{
				//q <= a
				machine.pop();
				if(a - q > m) continue;
				else
				{
					ok = true;
					machine.push(-(a+s));
					break;
				}
			}
		}
		//cout << a << " " << s << " " << ok << endl;
		if(!ok)
		{
			tot++;
			machine.push(-(a+s));
		}
	}

	int ans = n - tot;
	cout << ans << endl;

	return 0;
}