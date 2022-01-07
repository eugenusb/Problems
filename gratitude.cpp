#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)
#define R real
#define I imag
#define F first
#define S second

using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

map<string, int> dic;
map<string, int> app;
map<string, int> code;

int main()
{
	int n,k;
	cin >> n >> k;
	string s;
	getline(cin,s);

	forn(i,3*n)
	{
		string s;
		getline(cin,s);
		if(dic.find(s) == dic.end())
		{
			dic[s] = 1;
			app[s] = i;
		}
		else
		{
			dic[s]++;
			app[s] = i;
		}
	}

	vector< pair<par, string > > v;

	fora(p,dic)
	{
		string s = p.F;
		int cant = p.S;
		int pos = app[s];
		v.pb(mp(mp(-cant,-pos),s));
	}

	sort(v.begin(), v.end());

	forn(i,min(k,(int)v.size()))
	{
		cout << v[i].S << endl;
	}

	return 0;
}