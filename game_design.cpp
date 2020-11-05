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

map<char, char> op;
map<char, int> dir;

int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0,-1};

string rose = "RULD";

int main()
{
	op['D'] = 'U';
	op['U'] = 'D';
	op['L'] = 'R';
	op['R'] = 'L';

	forn(i,4) dir[rose[i]] = i;

	string s;

	cin >> s;
	int m = s.size();
	set< par > used;
	bool ok = true;
	used.insert({0,0});

	par cur = mp(0,0);

	for(int i = (m-1); i >= 0; i--)
	{
		char d = op[s[i]];
		int ind = dir[d];

		cur.F += dx[ind];
		cur.S += dy[ind];
		/*
		cout << d << endl;
		cout << cur.F << " " << cur.S << endl;
		*/
		if(used.find(cur) != used.end())
		{
			ok = false;
			break;
		}
		if(i > 0)
		{
			char dnext = op[s[i-1]];
			int indnext = dir[dnext];

			par cnd = cur;
			cnd.F += dx[indnext]; cnd.S += dy[indnext];

			while(used.find(cnd) != used.end())
			{
				cur.F += dx[ind];
				cur.S += dy[ind];
				if(used.find(cur) != used.end())
				{
					ok = false;
					break;
				}
				cnd = cur;
				cnd.F += dx[indnext]; cnd.S += dy[indnext];
			}
			if(ok)
			{
				par block = cur;
				block.F += dx[ind];
				block.S += dy[ind];
				if(block == mp(0,0))
				{
					ok = false;
					break;
				}
				used.insert(block);
			}	
			else break;
		}
	}

	if(ok)
	{
		int n = (int)(used.size());
		n--;
		cout << cur.F << " " << cur.S << endl;
		cout << n << endl;
		fora(p, used)
		{
			if(p != mp(0,0))
				cout << p.F << " " << p.S << endl;
		}
	}
	else
	{
		cout << "impossible" << endl;
	}
	return 0;
}