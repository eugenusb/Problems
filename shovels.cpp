#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

const int MAXP = (int)(1e5);
const int PRI = 9592;
int primos[PRI];
vector<int> ans;

void criba()
{ 
	bool prime[MAXP+10];
	memset(prime, true, sizeof(prime)); 
  
  	for(tint p = 3; p <= MAXP; p += 2) 
    {
        if (prime[p]) 
        {
            for(tint i = (tint)(p*p); i <= MAXP; i += p) 
            	prime[i] = false; 
        }
    }
    int j = 1; primos[0] = 2; 
    for(int i = 3; i <= MAXP; i += 2)
    {
    	if(prime[i])
    	{
    		primos[j] = i;
    		j++;
    	}
    }

    //cout << j << endl;
} 

void generate(int cur, int i, vector< par > & divi)
{
	//cout << cur << " " << i << endl;
	if(i == divi.size())
	{
		ans.pb(cur);
		return;
	}
	int p = divi[i].F; int pot = divi[i].S;
	int mul = 1;
	forn(a, pot+1)
	{
		generate(cur * mul, i+1, divi);
		mul *= p;
	}
}

int main()
{
	int t; cin >> t;
	int n,k;
	criba();

	forn(caso,t)
	{
		cin >> n >> k;

		int nn = n;
		vector< par > divi;

		forn(i, PRI)
		{
			if(nn % primos[i] == 0)
			{
				int pot = 0;
				while(nn % primos[i] == 0)
				{
					pot++;
					nn /= primos[i];
				}
				divi.pb(mp(primos[i], pot));
			}
		}
		if(nn > 1) divi.pb(mp(nn,1));
		ans.clear();
		generate(1,0,divi);
		sort(ans.begin(), ans.end());
		//fora(d,ans) cout << d << endl;
		int best = ans[0];
		forn(i, ans.size())
		{
			if(ans[i] > k) break;
			best = ans[i];
		}

		cout << n/best << endl;
	}

	return 0;
}