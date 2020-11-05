#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> par;

const int MAX = 105;

struct Matrix
{
	double mat[MAX][MAX];

	Matrix(int n)
	{
		forn(i,n)
			forn(j,n)
				mat[i][j] = 0;
	}
};

Matrix matMult(Matrix &m1, Matrix &m2, int n)
{
	Matrix ans(n);

	forn(i,n)
	{
		forn(j,n)
		{
			ans.mat[i][j] = 0;
			forn(k,n)
			{
				ans.mat[i][j] += (m1.mat[i][k] * m2.mat[k][j]);
			}
		}
	}

	return (ans);
}

Matrix matSum(Matrix &m1, Matrix &m2, int n)
{
	Matrix ans(n);

	forn(i,n)
	{
		forn(j,n)
		{
			ans.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
		}
	}

	return (ans);
}

Matrix expo(Matrix &M, int p, int n)
{
	Matrix ans(n);

	if(p == 0)
	{
		forn(i,n) ans.mat[i][i] = 1;
		return (ans);
	}
	if(p == 1) return M;

	int med = p / 2;

	ans = expo(M, med, n);

	ans = matMult(ans,ans,n);

	if(p & 1)
	{
		ans = matMult(ans, M, n);
	}

	return (ans);
}

Matrix sum_power(Matrix &M, int p, int n)
{
	Matrix ans(n);

	if(p <= 1)
	{
		forn(i,n) ans.mat[i][i] = 1;
		if(p == 1) ans = matSum(ans, M, n);

		return (ans);
	}

	int med = (p - 1) / 2;

	ans = sum_power(M,med,n);

	Matrix A_m = expo(M,med+1,n);

	Matrix ans1 = matMult(A_m, ans, n);

	if((p & 1) == 0)
	{
		A_m = matMult(A_m, A_m, n);
		//A_m = matMult(A_m, M, n);
		ans1 = matSum(ans1, A_m, n);
	}

	ans = matSum(ans, ans1, n);

	/*
	cout << p << " expo " << endl;
	forn(i,n)
	{
		forn(j,n)
		{
			cout << ans.mat[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return (ans);
}

int d[MAX][MAX];

int main()
{
	int t,n,m,p,u,v,c;
	cin >> t;
	cout.setf(ios::fixed | ios::showpoint);
    cout.precision(10);

    forsn(caso,1,t+1)
    {
        cin >> n >> m >> p;
        forn(i,n) forn(j,n) d[i][j] = -1;
        forn(i,n) d[i][i] = 0;

        forn(i,m)
        {
        	cin >> u >> v >> c; u--; v--;
        	d[u][v] = c; d[v][u] = c;
        }

        forn(k,n)
        {
        	forn(i,n)
        	{
        		forn(j,n)
        		{
        			if(d[i][k] == -1 or d[k][j] == -1) continue;
        			if(d[i][j] == -1 or d[i][j] > (d[i][k] + d[k][j]))
        			{
        				d[i][j] = d[i][k] + d[k][j];
        			}
        		}
        	}
        }
        
        Matrix A(n);

        forn(i,n)
        {
        	forn(j,n)
        	{
        		if(i != j) A.mat[i][j] = 1 / (n-1 + .0);
        	}
        }

        Matrix D(n);

        forn(i,n)
        {
        	forn(j,n)
        	{
        		D.mat[i][j] = d[i][j];
        	}
        }

        A = sum_power(A,p-1,n);
        
        /*
        cout << "D" << endl;
        forn(i,n)
        {
        	forn(j,n)
        	{
        		cout << D.mat[i][j] << " "; 
        	}
        	cout << endl;
        }
        cout << "A" << endl;
        forn(i,n)
        {
        	forn(j,n)
        	{
        		cout << A.mat[i][j] << " "; 
        	}
        	cout << endl;
        }
		*/
        Matrix X = matMult(D,A,n);
        /*
        cout << "X" << endl;
        forn(i,n)
        {
        	forn(j,n)
        	{
        		cout << X.mat[i][j] << " "; 
        	}
        	cout << endl;
        }
        */
        double ans = 0.0;

        forn(i,n) ans = (ans + X.mat[i][0] / (n - 1 + 0.0));

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}