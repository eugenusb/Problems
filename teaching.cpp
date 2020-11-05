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
typedef pair<tint,tint> par;

int main()
{
	int t; cin >> t;
    string s;

    forsn(caso,1,t+1)
    {
        cin >> s;
        
        int ans = 0;

        deque<char> q;

        reverse(s.begin(), s.end());

        forn(i,s.size())
        {
            char c = s[i];

            if(q.empty())
            {
                q.pb(c);
            }
            else
            {
                char d = q.back();
                if(d == c)
                {
                    q.pop_back();
                    ans += 10;
                }
                else
                {
                    q.pb(c);
                }
            }
        }

        int n = (int)(q.size());
        n /= 2;
        ans += 5 * n;

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}