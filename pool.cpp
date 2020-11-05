#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define EPS 1e-8
using namespace std;

typedef long long int tint;
typedef pair<double, double> par;

par source[110];

int main()
{
	int t,n; cin >> t;    
    double V,X;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(10);

    forsn(caso,1,t+1)
    {
        cin >> n >> V >> X;
        forn(i,n)
        {
            cin >> source[i].S >> source[i].F;
        }
        sort(source, source+n);

        double A,B,C,D; A = 0; B = 0; C = 0; D = 0;
        bool ok = true;

        forn(i,n)
        {
            if(source[i].F < X)
            {
                A += source[i].S;
                C += source[i].S * source[i].F;
            }
            else
            {
                B += source[i].S;
                D += source[i].S * source[i].F;
            }
        }

        double ans;
        double det = A * D - B * C;

        //cout << A << " " << B << " " << C << " " << D << " " << det << endl;

        if(fabs(det) < EPS)
        {
            if(A > B)
            {
                double T = V / A;
                double to = (V - B*T) / (A - B);
                ans = max(to, T - to);
                if(fabs(C - A * X) > EPS) ok = false;
            }
            else
            {
                double T = V / B;
                double t1 = (V - A*T) / (B - A);
                ans = max(t1, T - t1);
                if(fabs(D - B * X) > EPS) ok = false;
            }
        }
        else
        {
            ans = max(D * V - B * V * X, - C * V + A * V * X) / det;
            if(ans < -EPS) ok = false;
        }

        if(ok)
            cout << "Case #" << caso << ": " << ans << endl;
        else
            cout << "Case #" << caso << ": IMPOSSIBLE" << endl;
    }

	return 0;
}