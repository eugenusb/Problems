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


int a[7200];
vector<int> divi[200100];

void init()
{
    forsn(d,2,200010)
    {
        for(int q = 1; q * d <= 200010; q++)
        {
            divi[d * q].pb(d);
        }
    }
}

int main()
{
	int t; cin >> t;    
    int n,a;
    init();

    forsn(caso,1,t+1)
    {
        cin >> n;
        set<int> s;
        map<int,tint> cant;

        forn(i,n)
        {
            cin >> a;
            s.insert(a);
            if(cant.find(a) == cant.end())
            {
                cant[a] = 1;
            }
            else cant[a]++;
        }

        tint ans = 0;

        if(cant.find(0) != cant.end())
        {
            ans = ( cant[0] * (cant[0]-1) * (cant[0]-2) ) / 6 + ((cant[0] * (cant[0]-1))/2) * (n - cant[0]);
        }
        if(cant.find(1) != cant.end())
        {
            ans += ( ( cant[1] * (cant[1]-1) * (cant[1]-2) ) / 6 );

            for(auto elem : s)
            {
                if( (elem > 1) and cant[elem] >= 2)
                {
                    ans += ( (cant[1] * (cant[elem] * (cant[elem] - 1)) / 2 ) );
                }
            }
        }
        tint ans1 = 0;

        for(auto elem : s)
        {
            if(elem <= 1) continue;

            for(auto d : divi[elem])
            {
                if(cant.find(d) != cant.end())
                {
                    int q = elem / d;
                    //cout << elem << " " << d << " " << q << endl;
                    if(q != 1 and cant.find(q) != cant.end())
                    {
                        if(q == d)
                        {
                            ans += (cant[elem] * (cant[d] * (cant[d] -1)) / 2);
                        }
                        else
                        {
                            ans1 += (cant[elem] * cant[d] * cant[q]);
                        }
                    }
                    //cout << ans << " " << ans1 << endl;
                }
            }
        }

        ans1 /= 2;
        ans += ans1;

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}