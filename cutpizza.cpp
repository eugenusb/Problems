#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 

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
using namespace __gnu_pbds; 
using namespace std; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

typedef long long int tint;
typedef pair<int,int> par;

par hor[100100];
par ver[100100];

int main()
{
	int x,y;
	cin >> x >> y;
	tint h,v;
	cin >> h >> v;
	tint ver_inter = 0;
	tint hor_inter = 0;

	forn(i,h)
	{
		cin >> hor[i].F >> hor[i].S;
	}

	forn(i,v)
	{
		cin >> ver[i].F >> ver[i].S;
	}

	sort(hor, hor+h);
	sort(ver, ver+v);

	ordered_set horizontal;

	forn(i,h)
	{
		horizontal.insert(hor[i].S);
		int u = horizontal.order_of_key(hor[i].S);
		//cout << hor[i].F << " " << hor[i].S << " " << u << " " << (i-u) << endl;
		hor_inter += (i-u);
	}

	ordered_set vertical;

	forn(i,v)
	{
		vertical.insert(ver[i].S);
		int u = vertical.order_of_key(ver[i].S);
		//cout << ver[i].F << " " << ver[i].S << " " << u << " " << (i-u) << endl;
		ver_inter += (i-u);
	}

	tint ans = h + v + (h*v) + ver_inter + hor_inter + 1;

	cout << ans << endl;

	return 0;
}