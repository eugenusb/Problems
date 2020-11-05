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


tint S[1000100];
tint X[1000100];
tint Y[1000100];

int main()
{
	int t,n,k;
	cin >> t;
	tint A, B, C, D;

	forsn(caso,1,t+1)
	{
		cin >> n >> k;

		forn(i,k)
		{
			scanf("%lld", &S[i]);
		}

		cin >> A >> B >> C >> D;

		forsn(i,k,n)
		{
			S[i] = (A * S[i-2] + B * S[i-1] + C) % D;
		}

		forn(i,k)
		{
			scanf("%lld", &X[i]);
		}

		cin >> A >> B >> C >> D;

		forsn(i,k,n)
		{
			X[i] = (A * X[i-2] + B * X[i-1] + C) % D;
		}

		forn(i,k)
		{
			scanf("%lld", &Y[i]);
		}

		cin >> A >> B >> C >> D;

		forsn(i,k,n)
		{
			Y[i] = (A * Y[i-2] + B * Y[i-1] + C) % D;
		}

		tint excess = 0;
		tint cap_exp = 0;
		tint cap_red = 0;
		tint deficit = 0;

		forn(i,n)
		{
			if(S[i] > (X[i] + Y[i]))
			{
				excess += (S[i] - X[i] - Y[i]);
				cap_red += (Y[i]);
			}
			if(S[i] < X[i])
			{
				deficit += (X[i] - S[i]);
				cap_exp += Y[i];
			}
			if(S[i] >= X[i] and S[i] <= (X[i] + Y[i]))
			{
				cap_exp += (X[i] + Y[i] - S[i]);
				cap_red += (S[i] - X[i]);
			}
		}
		/*
		forn(i,n) cout << S[i] << " ";
		cout << endl;
		forn(i,n) cout << X[i] << " ";
		cout << endl;
		forn(i,n) cout << X[i] + Y[i] << " ";
		cout << endl;

		cout << excess << " " << deficit << " " << cap_red << " " << cap_exp << endl;
		*/
		tint ans = min(excess, deficit);

		excess -= ans;
		deficit -= ans;

		if(excess > 0)
		{
			// deficit = 0

			if(excess <= cap_exp)
			{
				ans += (excess);
			}
			else
			{
				ans = -1;
			}
		}
		else
		{
			// excess = 0

			if(deficit <= cap_red)
			{
				ans += deficit;
			}
			else
			{
				ans = -1;
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}