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

int nota[100100];
string ans[12] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int patt[7] = {2,2,1,2,2,2,1};

int main()
{
	int n; cin >> n;
	string answ = "desafinado";
	forn(i,n)
	{
		cin >> nota[i];
		nota[i]--;
		nota[i] %= 12;
	}
	forn(j,12)
	{
		set<string> av;
		av.insert(ans[j]);
		int cur = j;
		forn(i,7)
		{
			cur += patt[i];
			int ind = cur % 12;
			av.insert(ans[ind]);
		}
		bool ok = true;
		forn(i,n)
		{
			if(av.find(ans[nota[i]]) == av.end())
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
			//cout << j << endl;
			answ = ans[j];
			break;
		}
	}

	cout << answ << endl; 

	return 0;
}