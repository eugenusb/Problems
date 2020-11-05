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
int vis[110][110][4]; // -1 pending, 0 unseen, 1 seen, 2 fixed
map<char, int> pos;
map<char, char> op;

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};


bool valid(int a, int b)
{
    return (0 <= a and a < r and 0 <= b and b < c);
}

int bfs(int a, int b)
{
    //cout << a << " " << b << endl;
    forn(k,4) vis[a][b][k] = 1;
    vector< pair< par, int> > seen;
    forn(k,4) seen.pb(mp(mp(a,b),k));
    queue< pair< par, int> > q; q.push(mp(mp(a,b),0));    

    int cost = 0; bool ok = true;

    while(!q.empty())
    {
        pair< par, int> cur = q.front(); q.pop();
        par cur_pos = cur.F; int cur_dir = cur.S;
        char dir = tab[cur_pos.F][cur_pos.S];
        //cout << cur_pos.F << " " << cur_pos.S << " " << cur_dir << " " << dir << endl;
        if(dir != '.')
        {            
            par nex; int k = pos[dir];
            nex.F = cur_pos.F + dx[k];
            nex.S = cur_pos.S + dy[k];
            
            //cout << nex.F << " " << nex.S << endl;

            if(!valid(nex.F, nex.S))
            {
                vector< par > posit;

                for(int i = (int)seen.size()-1; i >= 0; i--)
                {
                    par p = seen[i].F;
                    if(tab[p.F][p.S] != '.')
                    {
                        posit.pb(p);
                        if(posit.size() == 8) break;
                    }                    
                }
                if(posit.size() == 8)
                {
                    ok = true;
                    tab[posit[0].F][posit[0].S] = op[tab[posit[4].F][posit[4].S]];
                    cost++;
                }
                else
                {
                    for(int i = (int)seen.size()-1; i >= 0; i--)
                    {
                        vis[seen[i].F.F][seen[i].F.S][seen[i].S] = -1;
                    }
                    ok = false;
                }
                break;
            }
            else
            {
                // valid position

                if(tab[nex.F][nex.S] != '.')
                {
                    if(vis[nex.F][nex.S][0] > 0) break;
                    if(vis[nex.F][nex.S][0] == -1)
                    {
                        //cout << nex.F << " " << nex.S << " OK " << ok << endl;
                        cost++;
                        forn(j,4) seen.pb(mp(mp(nex.F,nex.S),j));
                        break;
                    }
                    forn(j,4)
                    {
                        vis[nex.F][nex.S][j] = 1;
                        seen.pb(mp(mp(nex.F,nex.S),j));
                    }
                    q.push(mp(nex,0));
                }
                else
                {
                    if(vis[nex.F][nex.S][k] > 0) break;
                    vis[nex.F][nex.S][k] = 1;
                    seen.pb(mp(mp(nex.F,nex.S),k));
                    q.push(mp(nex,k));
                }
            }        
        }
        else
        {
            par nex;
            nex.F = cur_pos.F + dx[cur_dir];
            nex.S = cur_pos.S + dy[cur_dir];

            //cout << nex.F << " " << nex.S << endl;

            if(!valid(nex.F, nex.S))
            {             
                vector< par > posit;

                for(int i = (int)seen.size()-1; i >= 0; i--)
                {
                    par p = seen[i].F;
                    if(tab[p.F][p.S] != '.')
                    {
                        posit.pb(p);
                        if(posit.size() == 8) break;
                    } 
                }
                if(posit.size() == 8)
                {
                    ok = true;
                    tab[posit[0].F][posit[0].S] = op[tab[posit[4].F][posit[4].S]];
                    cost++;
                }
                else
                {
                    for(int i = (int)seen.size()-1; i >= 0; i--)
                    {
                        vis[seen[i].F.F][seen[i].F.S][seen[i].S] = -1;
                    }
                    ok = false;                
                }
                break;
            }
            else
            {
                // valid position

                if(tab[nex.F][nex.S] != '.')
                {
                    if(vis[nex.F][nex.S][0] > 0) break;
                    if(vis[nex.F][nex.S][0] == -1)
                    {
                        forn(j,4) seen.pb(mp(mp(nex.F,nex.S),j));
                        //cout << nex.F << " " << nex.S << " OK " << ok << endl;
                        cost++;
                        seen.pb(mp(mp(nex.F,nex.S),0));
                        break;
                    }
                    forn(j,4)
                    {
                        vis[nex.F][nex.S][j] = 1;
                        seen.pb(mp(mp(nex.F,nex.S),j));
                    }
                    q.push(mp(nex,0));
                }
                else
                {
                    if(vis[nex.F][nex.S][cur_dir] > 0) break;
                    vis[nex.F][nex.S][cur_dir] = 1;
                    seen.pb(mp(mp(nex.F,nex.S),cur_dir));
                    q.push(mp(nex,cur_dir));
                }
            }
        }
    }

    if(ok)
    {
        fora(el,seen)
        {
            //cout << el.F.F << " " << el.F.S << " " << el.S << endl;
            vis[el.F.F][el.F.S][el.S] = 2;
        }
    }

    return (cost);
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
                forn(k,4) vis[i][j][k] = 0;
            }
        }

        int ans = 0;
        bool ok = true;

        if(r == 1 or c == 1)
        {
            if(r == 1)
            {
                int fl = -1; int fr = -1;
                forn(j,c)
                {
                    if(tab[0][j] != '.')
                    {
                        fl = j;
                        if(tab[0][j] != '>')
                        {
                            tab[0][j] = '>';
                            ans++;
                        }
                        break;
                    }
                }
                for(int j = c-1; j > fl; j--)
                {
                    if(tab[0][j] != '.')
                    {
                        fr = j;
                        if(tab[0][j] != '<')
                        {
                            tab[0][j] = '<';
                            ans++;
                        }
                        break;
                    }
                }
                if( (fl == -1 and fr != -1) or (fr == -1 and fl != -1) )
                {
                    ok = false;
                    break;
                }
                else
                {
                    forsn(j,fl+1,fr-1)
                    {
                        if(tab[0][j] == 'v' or tab[0][j] == '^') ans++;
                    }
                }
            }
            else
            {
                int fu = -1; int fd = -1;
                forn(i,r)
                {
                    if(tab[i][0] != '.')
                    {
                        fu = i;
                        if(tab[i][0] != 'v')
                        {
                            tab[i][0] = 'v';
                            ans++;
                        }
                        break;
                    }
                }
                for(int i = r-1; i > fu; i--)
                {
                    if(tab[i][0] != '.')
                    {
                        fd = i;
                        if(tab[i][0] != '^')
                        {
                            tab[i][0] = '^';
                            ans++;
                        }
                        break;
                    }
                }
                if( (fu == -1 and fd != -1) or (fd == -1 and fu != -1) )
                {
                    ok = false;
                    break;
                }
                else
                {
                    forsn(i,fu+1,fd-1)
                    {
                        if(tab[i][0] == '<' or tab[i][0] == '>') ans++;
                    }
                }
            }
        }
        else
        {
            forn(i,r)
            {
                forn(j,c)
                {
                    if(!vis[i][j][0] and tab[i][j] != '.')
                    {
                        ans += bfs(i,j);
                    }
                }
            }
            forn(i,r)
            {
                forn(j,c)
                {
                    if(vis[i][j][0] == -1 and tab[i][j] != '.')
                    {
                        ans++;
                    }
                }
            }
            forn(i,r)
            {
                forn(j,c)
                {
                    if(vis[i][j][0] == -1 and tab[i][j] != '.')
                    {
                        //cout << "Pending " << i << " " << j << endl;
                        int best = 1; int index = -1;
                        char orig = tab[i][j];
                        forn(k,s.size())
                        {
                            if(s[k] == tab[i][j]) continue;
                            tab[i][j] = s[k];
                            int cnd = bfs(i,j);
                            if(vis[i][j][0] != -1 and cnd <= best)
                            {
                                best = cnd;
                                index = k;
                            }
                            tab[i][j] = orig;
                            //cout << "Result " << vis[i][j][0] << endl;
                        }
                        
                        if(index == -1)
                        {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }

        if(ok)
            cout << "Case #" << caso << ": " << ans << endl;
        else
            cout << "Case #" << caso << ": IMPOSSIBLE" << endl;
    }

	return 0;
}