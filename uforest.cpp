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


int dp[110];
bool vis[110];
vector<int> ch[110];
string cool[10];
string univ;

void dfs(int v)
{
    vis[v] = true;

    int acum = 1;

    fora(u, ch[v])
    {
        if(!vis[u])
        {
            dfs(u);
            acum += dp[u];
        }
    }

    //cout << v << " " << acum << endl;

    dp[v] = acum;
}


bool in(string a, string b)
{
    int n = a.size(); int m = b.size();

    forn(i,m-n+1)
    {
        bool is = true;
        forn(j,n)
        {
            if(a[j] != b[i+j])
            {
                is = false;
                break;
            }
        }
        if(is) return (true);
    }

    return (false);
}


int main()
{
	int t; cin >> t;
    int n,m,p;

    forsn(caso,1,t+1)
    {
        cin >> n;
        forn(i,n+1)
        {
            ch[i].clear();
            vis[i] = false;
            dp[i] = 0;
        }
        forn(i,n)
        {
            cin >> p;
            ch[p].pb(i+1);
        }
        fora(el, ch[0])
        {
            dfs(el);
        }

        cin >> univ;
        cin >> m;
        forn(i,m) cin >> cool[i];

        int S = 50000;

        vector<int> ans(m,0);
        //random_device dev;
        //mt19937 rng(dev());
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        forn(sim, S)
        {
            vector<int> active = ch[0];
            vector<int> weights;
            int W = 0;
            fora(v, active)
            {
                weights.pb(dp[v]);
                W += dp[v];
            }
            string carr = "";

            forn(paso,n)
            {
                //int r = rand() % W + 1;
                
                //uniform_int_distribution<std::mt19937::result_type> ud(1,W);
                //int r = ud(rng);

                int r = rng() % W + 1;

                int index = -1;
                int acum = 0;
                forn(i, active.size())
                {
                    if(acum < r and r <= acum + weights[i])
                    {
                        index = i;
                        break;
                    }
                    else acum += weights[i];
                }

                int course = active[index];
                carr += univ[course-1];
                active.erase(active.begin() + index);
                weights.erase(weights.begin() + index);
                W -= dp[course];
                fora(el,ch[course])
                {
                    active.pb(el);
                    weights.pb(dp[el]);
                    W += dp[el];
                }                
            }

            forn(j,m)
            {
                if(in(cool[j], carr))
                {
                    ans[j]++;
                }
            }
        }
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(10);

        cout << "Case #" << caso << ": ";
        forn(i,m-1) cout << ans[i] / (S + 0.0) << " ";
        cout << (ans[m-1] / (S + 0.0)) << endl;
    }

	return 0;
}