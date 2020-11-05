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

bool br[500100];

int main()
{
	int n,c,b,z;
	cin >> n >> c >> b;
	string ans = "";
	forn(i,n) ans += '0';

	forn(i,b)
	{
		scanf("%d", &z);
		br[z-1] = true;
	}

	int cur = 1;
	if(c & 1)
	{
		ans[0] = '1';
		c--;
		cur = 2;
	}
	//c is even
	int ones = c/2;

	while(ones)
	{
		if(!br[cur])
		{
			ans[cur] = '1';
			cur += 2;
			ones--;
		}
		else
		{
			cur++;
		}
	}

	cout << ans << endl;

	return 0;
}