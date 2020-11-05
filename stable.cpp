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

char tab[35][35];
bool in[30];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};


bool valid(int a, int b, int r, int c)
{
	return ( (0 <= a) and (a < r) and (0 <= b) and (b < c) );
}


string check(vector<string> & orden, int r, int c)
{
	string ans = "";
	char curtab[30][30];
	forn(i,30) forn(j,30) curtab[i][j] = '.';

	int N = orden.size();

	forn(n,N)
	{
		string loc = orden[n];		
		//cout << loc << endl;

		bool poss1 = true;

		forn(a, loc.size())
		{
			char let = loc[a];
			bool first = true;
			for(int i = (r-1); i >= 0; i--)
			{
				vector<int> line;

				forn(j,c)
				{
					if(tab[i][j] == let)
					{
						line.pb(j);
					}
				}
				int l = (int)(line.size());
				if(i < (r - 1) and l and first)
				{
					first = false;
					fora(e, line)
					{
						if(curtab[i+1][e] == '.')
						{
							poss1 = false;
							break;
						}
					}
				}
				forn(k,i)
				{
					fora(e,line)
					{
						if(curtab[k][e] != '.')
						{
							poss1 = false;
							break;
						}
					}
				}
				if(!poss1) break;

				fora(e,line) curtab[i][e] = let;
			}
		}
		if(!poss1)
		{
			forn(a, loc.size())
			{
				char let = loc[a];

				for(int i = (r-1); i >= 0; i--)
				{
					forn(j,c)
					{
						if(tab[i][j] == let)
						{
							curtab[i][j] = '.';
						}
					}
				}
			}

			reverse(loc.begin(), loc.end());
			poss1 = true;
			bool first = true;
			forn(a, loc.size())
			{
				char let = loc[a];

				for(int i = (r-1); i >= 0; i--)
				{
					vector<int> line;

					forn(j,c)
					{
						if(tab[i][j] == let)
						{
							line.pb(j);
						}
					}
					int l = (int)(line.size());
					if(i < (r - 1) and l and first)
					{
						first = false;
						fora(e, line)
						{
							if(curtab[i+1][e] == '.')
							{
								poss1 = false;
								break;
							}
						}
					}
					forn(k,i)
					{
						fora(e,line)
						{
							if(curtab[k][e] != '.')
							{
								poss1 = false;
								break;
							}
						}
					}
					if(!poss1) break;

					fora(e,line) curtab[i][e] = let;
				}
			}
			if(!poss1)
			{
				return ("-1");
			}
			else ans += loc;
		}
		else ans += loc;
	}

	return (ans);
}



int main()
{
	int t; cin >> t;
	int r,c;

    forsn(caso,1,t+1)
    {
    	cin >> r >> c;
    	forn(i,r) forn(j,c) cin >> tab[i][j];

    	forn(i,30) in[i] = false;

    	vector<string> orden;

	   	for(int i = (int)(r-1); i >= 0; i--)
    	{
    		string local = "";
    		forn(j,c)
    		{
    			int cur = (int)(tab[i][j] - 'A');

    			if(!in[cur])
    			{
    				in[cur] = true;
    				local += tab[i][j];    				
    			}
    		}
    		//orden = local + orden;
    		if(local != "") orden.pb(local);
    	}
    	//reverse(orden.begin(), orden.end());
    	string ans = check(orden, r, c);

        cout << "Case #" << caso << ": " << ans << endl;
    }

    return 0;
}