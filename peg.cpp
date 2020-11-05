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

int r,c;
char tab[110][110];
int vis[110][110];
map<char, int> pos;
map<char, char> op;

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};

bool valid(int a, int b)
{
    return (0 <= a and a < r and 0 <= b and b < c);
}

bool nosale(int i, int j, int dir)
{
    for(int k = 1; true; k++)
    {
        int a = i + k * dx[dir];
        int b = j + k * dy[dir];

        if(!valid(a,b))
        {
            return (false);
        }
        else
        {
            if(tab[a][b] != '.') return true;
        }
    }

    return true;
}

int main()
{
    pos['^'] = 0; pos['>'] = 1;
    pos['<'] = 3; pos['v'] = 2;

    op['^'] = 'v'; op['>'] = '<';
    op['<'] = '>'; op['v'] = '^';
    string s = "<>v^";

	int t; cin >> t;
    

    forsn(caso,1,t+1)
    {
        cin >> r >> c;
        forn(i,r)     
        {
            forn(j,c)
            {
                cin >> tab[i][j];
                vis[i][j] = 0;
            }
        }

        int ans = 0;
        bool ok = true;

        forn(i,r)
        {
            forn(j,c)
            {
                if(tab[i][j] != '.' and !vis[i][j])
                {
                    int dir = pos[tab[i][j]];

                    ok = nosale(i,j,dir);

                    if(!ok)
                    {
                        forn(l,4)
                        {
                            if(nosale(i,j,l))
                            {
                                ok = true;
                                break;
                            }
                        }

                        if(!ok)
                        {
                            break;
                        }
                        else ans++;
                    }
                }
            }
            if(!ok) break;
        }

        if(ok)
            cout << "Case #" << caso << ": " << ans << endl;
        else
            cout << "Case #" << caso << ": IMPOSSIBLE" << endl;
    }

	return 0;
}