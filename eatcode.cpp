#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

tint c[100100];
tint e[100100];
tint a[100100];
tint b[100100];

double EPS = (1e-5);

bool solve(double L, double R, int iter, int s)
{
    cout << L << " " << R << " " << iter << " " << s << endl;
    if(iter == (s-1))
    {
        bool ok = (L <= c[s-1]) and ((e[s-1] - R) >= 0);
        ok = ok and (e[s-1] * L <= c[s-1] * R);

        return (ok);
    }

    double lo = 0.0; double hi = 1.0;

    while(hi - lo > EPS)
    {
        double x = (lo + hi) / 2.0;

        if(solve(L - x * c[iter], R - e[iter] + x * e[iter], iter+1, s))
        {
            hi = x;
        }
        else lo = x;
    }

    return (solve(L - hi * c[iter], R - e[iter] + hi * e[iter], iter + 1, s));
}

int main()
{
	int t; cin >> t;
    int d,s;
    char cod[2];
    cod[0] = 'N'; cod[1] = 'Y';

    forsn(caso,1,t+1)
    {
        cin >> d >> s;
        forn(i,s) cin >> c[i] >> e[i];
        forn(i,d) cin >> a[i] >> b[i];

        string ans = "";

        forn(i,d)
        {
            ans += cod[solve(a[i],b[i],0,s)];
        }
        
        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}