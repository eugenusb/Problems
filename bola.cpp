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

int sg[110][110];

void calc()
{
	sg[0][0] = 0;
	int M = 101;

	forsn(i,1,M)
	{
		forsn(j,1,i)
		{
			set<int> moves;

			forsn(k,1,i)
			{
				int ni = i - k;
				int nj = j;
				if(ni == nj) continue;
				if(ni < nj) swap(ni,nj);
				moves.insert(sg[ni][nj]);
			}
			forsn(k,1,j)
			{
				int ni = i;
				int nj = j - k;
				if(ni == nj) continue;
				if(ni < nj) swap(ni,nj);
				moves.insert(sg[ni][nj]);
			}
			forsn(k,1,j)
			{
				int ni = i - k;
				int nj = j - k;
				moves.insert(sg[ni][nj]);	
			}


			int r = 0;
			while(moves.find(r) != moves.end())
			{
				r++;
			}
			sg[i][j] = r;

			//cout << i << " " << j << " " << sg[i][j] << endl;
		}
	}
}

int main()
{
	calc();
	int n; cin >> n;
	int a,b;
	int ans = 0;
	bool win = false;
	forn(i,n)
	{
		cin >> a >> b;
		if(a < b) swap(a,b);
		if(a == b) win = true;
		ans = (ans ^ sg[a][b]);
		//cout << sg[a][b] << endl;
	}
	if(win) ans = 1;
	if(ans) cout << "Y" << endl;
	else cout << "N" << endl;

	return 0;
}