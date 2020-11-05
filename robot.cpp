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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// NESW

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};

int main()
{
	int t; cin >> t;
    int n,R,C;
    int x,y;
    string s;

    map<char, int> code;
    code['N'] = 0; code['E'] = 1;
    code['S'] = 2; code['W'] = 3;

    forsn(caso,1,t+1)
    {
        cin >> n >> R >> C >> x >> y;
        cin >> s;
        set< par > vis;
        vector< ordered_set > hor(R+1);
        vector< ordered_set > ver(C+1);
        vis.insert(mp(x,y));
        hor[x].insert(y);
        ver[y].insert(x);
        int curx = x; int cury = y;

        forn(i,n)
        {
            int k = code[s[i]];
            curx += dx[k];
            cury += dy[k];

            //cout << "antes " << curx << " " << cury << endl;

            if(vis.find(mp(curx,cury)) != vis.end())
            {
                //cout << "FOUND " << endl;
                switch(s[i])
                {
                    case('E'):
                    {
                        int hi = C;
                        int lo = cury;
                        int tot = hor[curx].order_of_key(cury);

                        while(hi - lo > 1)
                        {
                            int med = (hi + lo) / 2;

                            int cant = hor[curx].order_of_key(med+1) - tot;

                            if(cant < (med + 1 - cury))
                            {
                                hi = med;
                            }
                            else lo = med;
                        }
                        cury = hi;
                        break;
                    }
                    case('W'):
                    {
                        int lo = 1;
                        int hi = cury;

                        int tot = hor[curx].size() - hor[curx].order_of_key(cury);

                        while(hi - lo > 1)
                        {
                            int med = (hi + lo) / 2;
                            
                            int cant = hor[curx].size() - hor[curx].order_of_key(med) - tot;

                            if(cant < (cury - med))
                            {
                                lo = med;
                            }
                            else hi = med;
                        }
                        cury = lo;
                        break;
                    }
                    case('N'):
                    {
                        int lo = 1;
                        int hi = curx;

                        int tot = ver[cury].size() - ver[cury].order_of_key(curx);

                        while(hi - lo > 1)
                        {
                            int med = (hi + lo) / 2;
                            
                            int cant = ver[cury].size() - ver[cury].order_of_key(med) - tot;

                            if(cant < (curx - med))
                            {
                                lo = med;                       
                            }
                            else hi = med;
                        }
                        curx = lo;
                        break;
                    }
                    case('S'):
                    {
                        int hi = R;
                        int lo = curx;
                        int tot = ver[cury].order_of_key(curx);

                        while(hi - lo > 1)
                        {
                            int med = (hi + lo) / 2;

                            int cant = ver[cury].order_of_key(med+1) - tot;

                            if(cant < (med + 1 - curx))
                            {
                                hi = med;
                            }
                            else lo = med;
                        }
                        curx = hi;
                        break;
                    }
                }
            }
            //cout << "despues " << curx << " " << cury << endl;
            vis.insert(mp(curx,cury));
            hor[curx].insert(cury);
            ver[cury].insert(curx);
        }

        cout << "Case #" << caso << ": " << curx << " " << cury << endl;
    }
	return 0;
}