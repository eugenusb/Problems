#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define R real
#define I imag
#define sq(a) (a)*(a)
 
using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

int deck[40*40+10];

int main()
{
	int t; cin >> t;

	int r,s;

	forsn(caso, 1, t + 1)
	{
		cin >> r >> s;

		forn(i,s)
		{
			forn(j,r)
			{
				deck[i*r+j] = j+1;
			}
		}

		vector<int> moves;
		bool ready = false;

		while(!ready)
		{
			ready = true;

			int cur = r;
			int cnt = 1;
			int cut = -1;
			
			for(int i = r*s-2; i >= 0; i--)
			{
				if(deck[i] == cur)
				{
					cnt++;
				}
				else
				{
					if(cnt < s or deck[i] != cur - 1)
					{						
						cut = i+1;
						break;
					}
					else
					{
						cnt = 1;
						cur = deck[i];
					}
				}
			}

			if(cut != -1)
			{
				ready = false;
				for(int i = cut - 1; i >= 0; i--)
				{
					if(deck[i] == cur)
					{
						vector<int> tempa, tempb;
						forn(k,i+1) tempa.pb(deck[k]);
						forsn(k,i+1,cut) tempb.pb(deck[k]);						
						int a = (int) tempa.size();
						int b = (int) tempb.size();
						moves.pb(a); moves.pb(b);
						forn(k,b) deck[k] = tempb[k];
						forsn(k,b,b+a) deck[k] = tempa[k-b];
						break;
					}
				}
			}

			//forn(i,r*s) cout << deck[i] << " ";
			//cout << endl;
		}

		int ans = (int) moves.size() / 2;

		cout << "Case #" << caso << ": " << ans << endl;
		forn(i, ans)
		{
			cout << moves[2*i] << " " << moves[2*i+1] << endl;
		}
	}

	return 0;
} 