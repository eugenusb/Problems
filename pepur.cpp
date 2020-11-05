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


int main()
{
	int t; cin >> t;    
	int x,y; string s;

    forsn(caso,1,t+1)
    {
        cin >> x >> y >> s;
        int dist = (x + y);
        int ans = -1;
        int n = s.size();

        forn(i,n)
        {
            char c = s[i];

            switch(c)
            {
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
            }
            //cout << c << " " << x << " " << y << endl;
            if( (abs(x) + abs(y)) <= (i+1))
            {
                ans = i+1;
                break;
            }
        }

        cout << "Case #" << caso << ": ";
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
	return 0;
}