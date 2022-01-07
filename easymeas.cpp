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

struct dxy {tint d,x,y;};
dxy mcde(tint a, tint b) {
    dxy r, t;
    if (b == 0) {
        r.d = a; r.x = 1; r.y = 0;
    } else {
        t = mcde(b,a %b);
        r.d = t.d; r.x = t.y;
        r.y = t.x - a/b*t.y;
    }
    return r;
}

int main()
{
	int n; cin >> n;
	tint b,d;

	forn(i,n)
	{
		cin >> b >> d;
		
		struct dxy mcd = mcde(b,d);

		d /= mcd.d;
		tint sup_lim = (b - d + 1) / d;
		cout << sup_lim << endl;
	}

	return 0;
}