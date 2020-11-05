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

int v[310][310];
int best[310][310];

int main()
{
	int t; cin >> t;
    int K,R,C;

    forsn(caso,1,t+1)
    {
        cin >> R >> C >> K;
        
        int ans = R;

        forn(i,R)
            forn(j,C)
                cin >> v[i][j];
        
        forn(i,R)
        {
            set< par > in;
            int cant = 0;

            for(int j = C - 1; j >= 0; j--)
            {
                in.insert(mp(v[i][j],j));
                cant++;
                int mini = (*in.begin()).F;
                int maxi = (*in.rbegin()).F;

                while((maxi - mini) > K)
                {                    
                    cant--;
                    in.erase(mp(v[i][j+cant], j + cant));
                    mini = (*in.begin()).F;
                    maxi = (*in.rbegin()).F;
                }
                best[i][j] = cant;
            }
        }
        /*
        forn(i,R)
        {
            forn(j,C)
            {
                cout << best[i][j] << " ";
            }
            cout << endl;
        }
        */
        forn(i,R)
        {
            forn(j,C)
            {
                int cant = best[i][j];
                int row = i;

                for(int w = cant; w >= 2; w--)
                {
                    //cout << i << " " << j << " " << w << " " << row << endl;
                    while(row < R and best[row][j] >= w) row++;
                    ans = max(ans, (row - i) * w);
                    
                    if(row == R or best[row][j] == 1) break;
                }
            }
        }

        cout << "Case #" << caso << ": " << ans << endl;
    }
	return 0;
}