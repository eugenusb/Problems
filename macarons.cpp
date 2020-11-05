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

tint A[(1<<8)+10][(1<<8)+10];
const tint MOD = (tint)(1e9);
tint v[(1<<8)+10];

void init(int n)
{
	// create matrix of transitions and initial vector

	A[0][(1<<n)-1] = 1;
	v[0] = 1;

	int lim = (1<<(2*n));

	forsn(i,1,lim)
	{
		vector<int> base4(n,0);

		int k = i;
		int ind = 0;
		while(k)
		{
			int d = k % 4;
			base4[ind] = d;
			k /= 4;
			ind++;
		}

		int mask = 0;
		bool good = true;
		int comp_mask = (1<<n)-1;

		// second: generate the initial vector

		forn(j,n)
		{
			if(base4[j] == 2)
			{
				good = false;
				break;
			}
			if(base4[j] == 3)
			{
				if( (j == n-1) or base4[j+1] != 0)
				{
					good = false;
					break;
				}
				mask += (1<<j);
				mask += (1<<(j+1));
			}
			else
			{
				if(base4[j] == 1) mask += (1<<j);
			}
		}

		if(good) v[mask]++;

		good = true;
		mask = 0;
		forn(j,n)
		{
			if(base4[j] == 3)
			{
				if( (j == n-1) or base4[j+1] != 0)
				{
					good = false;
					break;
				}
				mask += (1<<j);
				mask += (1<<(j+1));
			}
			else
			{
				if(base4[j] != 0) mask += (1<<j);
				if(base4[j] == 2) comp_mask ^= (1<<j);
			}			
		}

		if(good)
		{
			A[mask][comp_mask]++;
		}
	}
}

tint B[(1<<8)+10][(1<<8)+10];
tint C[(1<<8)+10][(1<<8)+10];

void expo(int n, tint N)
{
	if(N == 0)
	{
		forn(i,(1<<n))
		{
			forn(j,(1<<n))
			{
				B[i][j] = 0;
			}
		}
		forn(i,(1<<n)) B[i][i] = 1;

		return;
	}
	if(N == 1)
	{
		forn(i,(1<<n))
		{
			forn(j, (1<<n))
			{
				B[i][j] = A[i][j];
			}
		}

		return;
	}

	tint med = N / 2ll;

	expo(n, med);

	forn(i,(1<<n))
	{
		forn(j, (1<<n))
		{
			C[i][j] = 0ll;

			forn(k, (1<<n))
			{
				C[i][j] = (C[i][j] + B[i][k] * B[k][j]) % MOD;
			}
		}
	}

	if(N & 1)
	{
		forn(i,(1<<n))
		{
			forn(j, (1<<n))
			{
				B[i][j] = 0ll;

				forn(k, (1<<n))
				{
					B[i][j] = (B[i][j] + C[i][k] * A[k][j]) % MOD;
				}
			}
		}
	}
	else
	{
		forn(i,(1<<n))
		{
			forn(j, (1<<n))
			{
				B[i][j] = C[i][j];
			}
		}
	}
	
}


int main()
{
	int n; tint m;

	cin >> n >> m;

	init(n);
	expo(n, m-1);
	// B = A^(m-1)


	// debug
	/*	
	cout << "A" << endl;
	forn(i,(1<<n))
	{
		forn(j,(1<<n))
		{
			cout << A[i][j] << " "; 
		}
		cout << endl;
	}
	
	cout << "B = A^(M-1)" << endl;
	forn(i,(1<<n))
	{
		forn(j,(1<<n))
		{
			cout << B[i][j] << " "; 
		}
		cout << endl;
	}
	cout << "v" << endl;
	forn(i,(1<<n)) cout << v[i] << " ";
	cout << endl;
	*/

	tint ans = 0ll;

	forn(i,(1<<n))
	{
		ans = (ans + B[(1<<n)-1][i] * v[i]) % MOD;
	}

	cout << ans << endl;
	
	return 0;
}