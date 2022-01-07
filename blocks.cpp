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

unordered_map<int, vector<int> > blocks;
unordered_map<int, vector<int> > indices;

int sol[100100];

int main()
{
	int n,k; cin >> n >> k;
	int num, col;

	forn(i,n)
	{
		cin >> num >> col;

		if(blocks.find(col) != blocks.end())
		{
			blocks[col].pb(num);
			indices[col].pb(i);
		}
		else
		{
			blocks[col] = vector<int>();
			indices[col] = vector<int>();
			blocks[col].pb(num);
			indices[col].pb(i);
		}
	}

	fora(p, blocks)
	{
		sort(p.S.begin(), p.S.end());
		blocks[p.F] = p.S;
	}

	fora(p, blocks)
	{
		int color = p.F;
		//cout << "COLOR " << color << endl;
		forn(i, p.S.size())
		{
			//cout << p.S[i] << " ";
			int ind = indices[color][i];
			sol[ind] = p.S[i];
		}
		//cout << endl;
	}

	bool sorted = true;

	forn(i,n-1)
	{
		if(sol[i] > sol[i+1])
		{
			sorted = false;
			break;
		}
	}

	//forn(i,n) cout << sol[i] << " ";
	//cout << endl;

	if(sorted) cout << "Y" << endl;
	else cout << "N" << endl;

	return 0;
}