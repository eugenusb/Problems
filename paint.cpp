#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sq(x) (x) * (x)
#define f first
#define s second

using namespace std;
typedef long long int tint;
typedef pair<int,int> par;

int m,n;
int l[100010];

int main()
{
	cin >> n >> m;
	forn(i,m) cin >> l[i];

	int rem = n - l[m-1];
	vector<int> p;
	p.pb(n - l[m-1] + 1);
	int cur = n - l[m-1] + 1;
	bool ok = true;
	for(int i = (m-2); i >= 0; i--)
	{
		if((n - l[i]) < i)
		{
			ok = false;
			break;
		}
		//cout << rem << " " << i << " " << n - l[i] + 1 << endl;
		if(rem < (i+1))
		{
			ok = false;
			break;
		}
		// rem >= (i+1)
		if(rem == (i+1))
		{			
			rem--;
			cur--;
			p.pb(cur);
		}
		else
		{
			int d = rem - i;
			if(d > l[i])
			{
				rem -= l[i];
				cur -= l[i];
				p.pb(cur);
			}
			else
			{
				rem -= d;
				cur -= d;
				p.pb(cur);
			}
		}
	}
	if(ok and p[m-1] != 1) ok = false;
	if(!ok) cout << "-1" << endl;
	else
	{
		reverse(p.begin(), p.end());
		forn(i,m-1) cout << p[i] << " ";
		cout << p[m-1] << endl;
	} 

	return 0;
}