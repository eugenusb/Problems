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

string pattern[55];

bool sub(string a, string b)
{
	int na = a.size(); int nb = b.size();

	if(na > nb) return false;

	forn(i,na)
	{
		if(a[i] != b[i]) return false;
	}

	return true;
}

int main()
{
	int t; cin >> t;
	int n;

	forsn(caso, 1, t+1)
	{
		cin >> n;

		forn(i,n) cin >> pattern[i];

		vector<string> suff;
		vector<string> pref;
		string mid = "";

		forn(i,n)
		{
			string cur = "";			
			int m = (int)pattern[i].size();
			int ini = 0; int fin = m;

			forn(k, m)
			{
				char c = pattern[i][k];
				if(c == '*')
				{
					ini = k;
					break;
				}
				else  cur += c;
			}
			//cout << "Prefix " << cur << endl;
			if(cur.size()) pref.pb(cur);

			cur = "";

			for(int k = m-1; k >= 0; k--)
			{
				char c = pattern[i][k];
				if(c == '*')
				{
					fin = k;
					break;
				}
				else cur += c;	
			}
			//cout << "Suffix " << cur << endl;
			if(cur.size()) suff.pb(cur);
			cur = "";

			forsn(k,ini,fin)
			{
				char c = pattern[i][k];
				if(c != '*') mid += c;
			}
			//cout << "Middle " << cur << endl;
		}

		sort(suff.begin(), suff.end());
		sort(pref.begin(), pref.end());
		bool ok = true;
		forn(i, pref.size()-1)
		{
			if(!sub(pref[i], pref[i+1]))
			{
				ok = false;
				break;
			}
		}
		forn(i, suff.size()-1)
		{
			//cout << suff[i] << " " << suff[i+1] << endl;
			if(!sub(suff[i], suff[i+1]))
			{
				ok = false;
				break;
			}
		}

		cout << "Case #" << caso << ": ";

		if(ok)
		{
			string prefix = !pref.empty() ? pref.back() : "";
			string suffix = !suff.empty() ? suff.back() : "";
			reverse(suffix.begin(), suffix.end());

			string ans = prefix + mid + suffix;
			cout << ans << endl;
		}
		else
		{
			cout << "*" << endl;
		}
	}
}