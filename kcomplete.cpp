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

int main()
{
	int t;
	cin >> t;
	int n,k; string s;

	forn(caso,t)
	{
		cin >> n >> k;
		cin >> s;

		int m = n / k;
		int ans = 0;

		forn(i,k/2)
		{
			vector<int> dic(28,0);
			int maxi = 0;
			int bind = -1;
			forn(j,m)
			{
				int l = j * k + i;
				int c = (int)(s[l] - 'a');
				//cout << s[l] << " ";
				dic[c]++;
				l = j * k + (k - 1 - i);
				c = (int)(s[l] - 'a');
				//cout << s[l] << " ";
				dic[c]++;
				if(maxi < dic[c])
				{
					maxi = dic[c];
					bind = c;
				}
			}
			//cout << endl;
			forn(j,28)
			{
				if(j != bind)
				{
					ans += dic[j];
				}
			}
		}

		if(k & 1)
		{
			vector<int> dic(28,0);
			int maxi = 0;
			int bind = -1;
			forn(j,m)
			{
				int l = j * k + k/2;
				int c = (int)(s[l] - 'a');
				//cout << s[l] << endl;
				dic[c]++;
				if(maxi < dic[c])
				{
					maxi = dic[c];
					bind = c;
				}
			}

			forn(j,28)
			{
				if(j != bind)
				{
					ans += dic[j];
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}