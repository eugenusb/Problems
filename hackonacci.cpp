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

int patt[7] = {0,1,0,0,1,1,1};
int hack[2010][2010];
int rothacko[2010][2010];
int ans[3];

int hacko(tint k)
{
	if(k==1) return 1;
	int ans = patt[(k+5)%7];
	return ans;
}

void rot(int n)
{
	int aux[n+1][n+1];
	forsn(i,1,n+1)
		forsn(j,1,n+1)
			aux[i][j] = rothacko[i][j];

	forsn(i,1,n+1)
		forsn(j,1,n+1)
			rothacko[i][j] = aux[n-j+1][i];
}

int solve(int n)
{
	int ans = 0;
	forn(i,n)
	{
		forn(j,n)
		{
			if(hack[i+1][j+1] != rothacko[i+1][j+1]) ans++;
		}
	}

	return (ans);
}

int main()
{
	int n,q; cin >> n >> q;

	forsn(i,1,n+1)
	{
		forsn(j,1,n+1)
		{
			tint ii = (tint)(i); tint jj = (tint)(j);
			tint k = ii*jj*ii*jj;
			hack[i][j] = hacko(k);
			rothacko[i][j] = hack[i][j];
		}
	}

	ans[0] = 0;
	/*
	forn(i,n)
	{
		forn(j,n)
		{
			cout << hack[i+1][j+1] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	forsn(k,1,4)
	{
		rot(n);
		/*
		cout << 90*k << " grados " << endl;
		forn(i,n)
		{
			forn(j,n)
			{
				cout << rothacko[i+1][j+1] << " ";
			}
			cout << endl;
		}
		*/
		ans[k] = solve(n);
	}

	int ang;

	forn(qu,q)
	{
		cin >> ang;
		ang /= 90;
		ang = ang % 4;
		cout << ans[ang] << endl;
	}

	return 0;
}