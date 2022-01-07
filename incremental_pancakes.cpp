#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define sq(a) (a)*(a)

using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;


tint calc_initial(tint dif)
{
	if(dif == 0) return 0;
	tint ans = (tint) ( (sqrt(1ll + 8ll*dif) - 1ll) / 2);
	ans--;

	while( (ans) * (ans + 1) < 2 * dif)
	{
		ans++;
	}
	ans--;
	return (ans);
}


tint calc_second(tint n, tint pile)
{
	tint disc = n*n + 2*n + 2 + 4*pile;
	tint k = (tint) (-(n+1) + sqrt(disc)) / 2;
	k--;

	while(n*k + k*(k-1) < pile)
	{
		k++;
	}
	k--;
	return (max(k,0ll));
}

tint L,R,ans;

void solve_bulk(tint n)
{	
	tint k_left = calc_second(n, L);
	tint k_right = calc_second(n+1, R);

	tint k = min(k_left, k_right);

	//cout << L << " " << R << " " << n << endl;
	//cout << k_left << " " << k_right << endl;

	L -= (n * k + k * (k - 1));
	R -= ((n + 1) * k + k * (k - 1));

	if(k_left <= k_right)
	{	
		n = n + 2 * k;
		if(L >= n)
		{
			L -= n;
			n++;

			if(R >= n)
			{
				R -= n;
			}
			else n--;
			ans = n;
			return;
		}
		else
		{
			n--;
			ans = n;
			return;
		}
	}
	else
	{
		n = n + 2 * k;
		if(L >= n)
		{
			L -= n;
			n++;

			if(R >= n)
			{
				R -= n;
				n++;
				if(L >= n)
				{
					L -= n;
				}
				else n--;
			}
			else n--;
			ans = n;
			return;
		}
		else
		{
			n--;
			ans = n;
			return;
		}
	}

	return;
}

void solve(tint n)
{
	if(L >= R)
	{
		L -= n * (n + 1) / 2;
		n++;
		if(L >= n) L -= n;
		else
		{
			n--;
			ans = n;
			return;
		}

		// L <= R
		n++;
		if(L == R)
		{
			solve_bulk(n);
		}
		else
		{
			if(R >= n)
			{
				R -= n;
				n++;
			}
			else
			{
				n--;
				ans = n;
				return;
			}

			solve_bulk(n);
		}
	}
	else
	{
		R -= n * (n + 1) / 2;
		n++;
		if(L < R)
		{
			if(R >= n)
			{
				R -= n;
				n++;
			}
			else
			{
				n--;
				ans = n;
				return;
			}	
		}	
		// R <= L
		solve_bulk(n);
	}

	return;
}

tint m,l,r;

void simulate(tint a, tint b)
{
	m = 1;

	while(max(a,b) >= m)
	{
		if(a >= b) a -= m;
		else b -= m;
		m++;
	}
	m--;
	l = a; r = b;
	return;
}

int main()
{
	int t; cin >> t;

	/*
	forsn(i,1,1000)
	{
		forsn(j,1,1000)
		{
			L = i; R = j;
			
			simulate(L,R);
			tint dif = abs(R - L);
			tint n = calc_initial(dif);
			solve(n);		

			if(L != l or R != r or ans != m)
			{
				cout << i << " " << j << endl;
				cout << "Correcto " << m << " " << l << " " << r << endl;
				cout << "Mine " << ans << " " << L << " "  << R << endl;
			}
		}
	}
	*/
	
	forsn(caso, 1, t+1)
	{
		cin >> L >> R;

		tint dif = abs(R - L);
		tint n = calc_initial(dif);
		solve(n);
		cout << "Case #" << caso << ": " << ans << " " << L << " " << R << endl;
	}

	return 0;
}