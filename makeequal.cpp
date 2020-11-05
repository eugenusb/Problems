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

int a[10100];

int main()
{
	int t,n; cin >> t;

	forn(caso, t)
	{
		cin >> n;
		int sum = 0;
		forn(i,n)
		{
			cin >> a[i];
			sum += a[i];
		}

		if(sum % n)
		{
			cout << -1 << endl;
		}
		else
		{
			int avg = sum / n;

			vector<int> ans;

			forsn(i,1,n)
			{
				if(a[i] > avg)
				{
					int d = a[i] - avg;
					int x = (a[i] - avg + i) / (i+1);
					if(a[i] >= x * (i+1))
					{
						ans.pb(i+1); ans.pb(1); ans.pb(x);
						a[i] -= x * (i+1);
						a[0] += x * (i+1);

						cout << a[i] << " " << a[0] << " " << x << endl;
					}
					else
					{
						x--;
						if(x)
						{
							ans.pb(i+1); ans.pb(1); ans.pb(x);
							a[i] -= x * (i+1);
							a[0] += x * (i+1);

							cout << a[i] << " " << a[0] << " " << x << endl;
						}
					}
				}
			}
			forsn(i,1,n)
			{
				if(a[i] > avg)
				{
					int d = a[i] - avg;
					int q = (a[i] - avg + i) / (i+1);
					// make a[i] = avg + q*(i+1)
					int x = avg + q*(i+1) - a[i];
					ans.pb(1); ans.pb(i+1); ans.pb(x);
					cout << a[i] << " " << a[0] << " " << x << endl;
					ans.pb(i+1); ans.pb(1); ans.pb(q);
					a[i] = avg;
					a[0] += (-x + q * (i+1));

					cout << a[i] << " " << a[0] << " " << q << endl;
				}
			}
			forsn(i,1,n)
			{
				if(a[i] < avg)
				{
					int x = avg - a[i];					
					ans.pb(1); ans.pb(i+1); ans.pb(x);
					a[0] -= x;
					a[i] += x;

					cout << a[i] << " " << a[0] << " " << x << endl;
				}
			}

			int k = (int) ans.size();
			k /= 3;
			cout << k << endl;
			forn(i,k)
			{
				cout << ans[3*i] << " " << ans[3*i+1] << " " << ans[3*i+2] << endl;
			}
		}
	}

	return 0;
}