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

tint M = (tint)(1e9);

tint mod(tint x)
{
	tint ans = ( x % M);
	if(ans < 0) ans += M;

	return (ans);
}

int glob;

map<char,int> cod;

vector<tint> calc(string s)
{
	//cout << glob << endl;
	vector<tint> ans(4,0);

	for(int h = 0; true; h++)
	{
		char c = s[glob];
		//cout << glob << " " << c << endl;
		if(c == ')')
		{
			glob++;
			return ans;
		}

		if('2' <= c and c <= '9')
		{
			tint mul = (tint)(c - '0');
			glob += 2;
			vector<tint> partial_ans = calc(s);
			forn(i,4) ans[i] = mod(ans[i] + mod(mul * partial_ans[i]));
		}
		else
		{
			ans[cod[c]]++;
			glob++;
		}
	}

	return (ans);
}


int main()
{
	int t; string s;
	cin >> t;

	cod['W'] = 0; cod['E'] = 1;
	cod['S'] = 2; cod['N'] = 3;

    forsn(caso,1,t+1)
    {
        cin >> s;
        int n = s.size();
        glob = 0;        
    
        s += ")";

        vector<tint> desp = calc(s);

        tint xans = 1ll + mod(desp[cod['E']] - desp[cod['W']]);
        tint yans = 1ll + mod(desp[cod['S']] - desp[cod['N']]);

        cout << "Case #" << caso << ": " << xans << " " << yans << endl;
    }

	return 0;
}