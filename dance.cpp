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

int s[1010];

int main()
{
	int t; cin >> t;
    int N, E;

    forsn(caso,1,t+1)
    {
        cin >> E >> N;
        forn(i,N)
        {
            cin >> s[i];
        }
        sort(s,s+N);
        int ans = 0;
        int cure = E;

        forn(i,N)
        {
            if(cure > s[i])
            {
                cure -= s[i];
                ans++;
            }
            else break;
        }

        forsn(i,1,N+1)
        {            
            forn(j,N-i+1)
            {
                // win the first i, lose the last j, draw the remaining
                int le = 0;
                int ri = N-1;
                int cur = E;
                int honor = 0;
                bool progress = true;

                while(progress)
                {
                    progress = false;
                    forsn(k,le,i)
                    {
                        if(cur > s[k])
                        {
                            cur -= s[k];
                            le++;
                            honor++;
                            progress = true;
                        }
                        else break;
                    }
                    ans = max(ans,honor);
                    for(int k = ri; k >= N-j; k--)
                    {
                        if(honor)
                        {
                            cur += s[k];
                            ri--;
                            progress = true;
                            honor--;
                        }
                        else break;
                    }
                }
                ans = max(ans, honor);
                //cout << i << " " << j << " " << cur << " " << ans << " " << le << " " << ri << endl;
            }
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}