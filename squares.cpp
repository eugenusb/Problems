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
typedef pair<int,int> par;


int a[100100];
int sum[100100];
vector<int> squares;
const int LIM = (int)(1e7);
int last[20000010];

void gen_squares()
{
	int k = 0;

	while(k * k <= LIM)
	{
		squares.pb(k * k);
		k++;
	}
}

int main()
{
	int t, n;
	cin >> t;
	gen_squares();
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL) ; cout.tie(NULL);
    forsn(caso,1,t+1)
    {
    	cin >> n;
    	//forn(i,n) cin >> a[i];
    	forn(i,n) scanf("%d",a+i);

    	int acum = 0;
    	//unordered_map<int, int> last;
    	//cout << "ok" << endl;    	
    	memset(last,0,20000010);
    	//cout << "ok" << endl;
    	//int LI = 1000;
    	forn(i,n)
    	{
    		acum += a[i];
    		sum[i] = acum;
    		last[acum + LIM]++;
    		/*
    		if(last.find(acum) != last.end())
    		{
    			last[acum]++;
    		}
    		else last[acum] = 1;
    		*/
    	}
    	//cout << "ok" << endl;
    	int tot = acum;
    	acum = 0;
    	int ans = 0;

    	forn(i,n)
    	{
    		fora(s, squares)
    		{
    			if(s + acum < 0) continue;
    			if(s + acum + LIM > 2*LIM) continue;
    			//if(last[s + acum + LIM]) cout << i << " " << acum << " " << s << " " << s + acum + LIM << endl;
    			//cout << s + acum + LIM << endl;
    			ans += last[s + acum + LIM];
    			/*
    			if(last.find(s + acum) != last.end() and last[s + acum])
    			{
    				//cout << i << " " << acum << " " << s << endl;
    				ans += last[s + acum];
    			}
    			*/
    		}
    		acum += a[i];
    		last[sum[i] + LIM]--;
    	}

        cout << "Case #" << caso << ": " << ans << endl;
    }

    return 0;
}