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

int tab[510][510];
int neg[510][510];
int bla[510][510];

int main()
{
	int n,p;
	cin >> n >> p;
	int a,b;

	forn(i,p)
	{
		cin >> a >> b;
		a--; b--;
		tab[a][b] = 1;
	}
	forn(i,p)
	{
		cin >> a >> b;
		a--; b--;
		tab[a][b] = 2;
	}

	forn(j,n)
	{
		if(j) neg[0][j] = neg[0][j-1];
		if(tab[0][j] == 1)
		{
			neg[0][j]++;
		}
		if(j) bla[0][j] = bla[0][j-1];
		if(tab[0][j] == 2)
		{
			bla[0][j]++;
		}
	}
	forsn(i,1,n)
	{
		neg[i][0] = neg[i-1][0];
		if(tab[i][0] == 1)
		{
			neg[i][0]++;
		}
		bla[i][0] = bla[i-1][0];
		if(tab[i][0] == 2)
		{
			bla[i][0]++;
		}
	}

	forsn(i,1,n)
	{
		forsn(j,1,n)
		{
			neg[i][j] = neg[i-1][j] + neg[i][j-1] - neg[i-1][j-1];
			bla[i][j] = bla[i-1][j] + bla[i][j-1] - bla[i-1][j-1];

			if(tab[i][j] == 1) neg[i][j]++;
			if(tab[i][j] == 2) bla[i][j]++;
		}
	}

	int preta = 0;
	int branca = 0;

	forn(i,n)
	{
		forn(j,n)
		{
			forn(l,n)
			{
				if(j+l >= n or i+l >= n) break;

				int negri = neg[i+l][j+l];
				if(j) negri -= neg[i+l][j-1];
				if(i) negri -= neg[i-1][j+l];
				if(i and j) negri += neg[i-1][j-1];

				int blanc = bla[i+l][j+l];
				if(j) blanc -= bla[i+l][j-1];
				if(i) blanc -= bla[i-1][j+l];
				if(i and j) blanc += bla[i-1][j-1];

				if(negri and blanc == 0) preta++;
				if(blanc and negri == 0) branca++;
			}
		}
	}

	cout << preta << " " << branca << endl;

	return 0;
}