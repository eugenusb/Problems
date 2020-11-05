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

int a[100100];

int dif[100100];
int cnt[100100];

int main()
{
	int t; cin >> t;
	int n,k;

	forn(caso,t)
	{
		scanf("%d %d", &n, &k);
		forn(i,n) scanf("%d", &a[i+1]);

		if(n == 1)
		{
			if(a[1] == k) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else
		{
			if(n == 2)
			{
				if(a[1] == k and a[2] >= k or a[1] <= k and a[2] == k) cout << "yes" << endl;
				else cout << "no" << endl;
			}
			else
			{
				bool ok = false;

				forn(i,n-2)
				{
					int j = i+2;
					int a = 0; int b = 0; int c = 0;
					forsn(l,i,j)
					{
						if(a[l] < k) a++;
						if(a[l] == k) b++;
						if(a[l] > k) c++;
					}
					
				}
				if(ok)
				{
					cout << "yes" << endl;
				}
				else cout << "no" << endl;
			}
		}
	}

	return 0;
}