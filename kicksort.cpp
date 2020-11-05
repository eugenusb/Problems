#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

// Header files, namespaces, 
// macros as defined above 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

typedef long long int tint;
typedef pair<int,int> par;

int a[100010];
int main() 
{
    int t; cin >> t;
    int n;

    forsn(caso,1,t+1)
    {
        cin >> n;
        oset s; forn(i,n) s.insert(i);
        forn(i,n) cin >> a[i];
        bool bad = true;

        int mini = 1; int maxi = n;
        forn(i,n-1)
        {
            int j = *(s.find_by_order( (n-i-1) / 2 ));
            //cout << j << " " << a[j] << endl;
            if(a[j] != maxi and a[j] != mini)
            {
                bad = false;
                break;
            }
            if(a[j] == maxi)
            {
                maxi--;
            }
            if(a[j] == mini)
            {
                mini--;
            }
            
            s.erase(j);
        }

        if(bad)
            cout << "Case #" << caso << ": YES" << endl;
        else
            cout << "Case #" << caso << ": NO" << endl;
    }

    return 0;
  
    return 0; 
} 