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


int col[1010];
par pos[1010];
vector< par > ocur[1010];
unordered_map<int,int> cant;
unordered_map<int, vector<int> > ap;

int main()
{
	int t; cin >> t;
    int n,k;

    forsn(caso,1,t+1)
    {
        cin >> n >> k;
        cant.clear(); ap.clear();

        forn(i,n)
        {
            cin >> pos[i].F;
            pos[i].S = i;
            ocur[i+1].clear();
        }
        forn(i,n) cin >> col[i];

        sort(pos, pos + n);

        int ans = (int)(1e9);

        int acum = 0;

        set< pair< par, int > > info;

        forn(i,n)
        {
            acum++;
            int color = col[pos[i].S];

            if(cant.find(color) == cant.end())
            {
                cant[color] = 1;
                info.insert(mp(mp(1,-pos[i].F), color));
                ap[color].pb(pos[i].F);
            }
            else
            {                
                info.erase(mp(mp(cant[color],-ap[color][cant[color]-1]), color));
                cant[color]++;
                info.insert(mp(mp(cant[color],-pos[i].F), color));
                ap[color].pb(pos[i].F);
            }
            ocur[cant[color]].pb(mp(pos[i].F, color));


            if(acum >= k)
            {
                // calculo costo
                set<int> used;

                cout << "ITER " << i << " " << pos[i].F << " " << col[pos[i].S] << endl;

                set< pair<par, int> >::iterator it;

                for(it = info.begin(); it != info.end(); it++)
                {
                    cout << (*it).F.F << " " << -(*it).F.S << " " << (*it).S << endl;
                }

                int miss = k;
                set< pair<par, int> >::reverse_iterator rit;
                rit = info.rbegin();
                int cnd = 0;

                while(miss)
                {
                    pair< par, int > pp = *rit;
                    int dogs = pp.F.F;
                    int po = -pp.F.S;
                    cout << dogs << " " << po << " " << pp.S << " Y FALTAN " << miss << endl;
                    vector<int> eq; eq.pb(pp.S);
                    int sum = dogs;
                    while(rit != info.rend())
                    {
                        rit++;
                        pair< par, int> aux = *rit;
                        //cout << (*rit).F.F << " " << -(*rit).F.S << " " << (*rit).S << endl;
                        int nd = aux.F.F;
                        int np = -aux.F.S;
                        if(nd == dogs and np == po)
                        {
                            eq.pb(aux.S);
                            sum += dogs;
                        }
                        else break;
                    }

                    if(sum >= miss)
                    {
                        if(sum == miss)
                        {
                            miss = 0;
                            cnd += (int)(eq.size()) * 2 * po;
                            cnd -= po;
                        }
                        else
                        {
                            int q = miss / dogs;
                            miss -= q * dogs;
                            cnd += 2 * q * po;

                            forn(j, ocur[miss].size())
                            {
                                int poso = ocur[miss][j].F;
                                int colo = ocur[miss][j].S;

                                if(used.find(colo) == used.end())
                                {
                                    cnd += poso;
                                    break;
                                }
                            }
                            miss = 0;
                        }
                    }
                    else
                    {
                        miss -= sum;
                        cnd += (int)(eq.size()) * 2 * po;
                        forn(j,eq.size())
                        {
                            used.insert(eq[j]);
                        }
                    }
                }
                cout << "RTA PARCIAL " << cnd << endl;

                ans = min(ans, cnd);
            }
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}