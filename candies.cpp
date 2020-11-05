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


tint s[500100];

int main()
{
	int t; cin >> t;
    int n,o; tint d;
    tint x1,x2,a,b,c,m,l;

    forsn(caso,1,t+1)
    {
        cin >> n >> o >> d;
        forn(i,n) cin >> s[i];
        /*
        cin >> x1 >> x2 >> a >> b >> c >> m >> l;
        s[0] = x1 + l; s[1] = x2 + l;
        
        forsn(i,2,n)
        {
            tint x = (a * x2 + b * x1 + c) % m;
            s[i] = x + l;
            x1 = x2; x2 = x;
        }
        */
        int l = 0; int r = 0;
        set<tint> acum; bool any = false;
        tint ans; int curo = 0;
        tint sum = 0;

        while(r < n)
        {
            //cout << r << endl;
            if(!(s[r] & 1))
            {
                sum += s[r];
                set<tint>::iterator it = acum.upper_bound(sum - d - 1ll);
                if(it != acum.end())
                {
                    if(any)
                    {
                        ans = max(ans, sum - (*it));
                        if(sum <= d) ans = max(ans, sum);
                    }
                    else
                    {
                        ans = sum - (*it);
                        if(sum <= d) ans = max(ans, sum);
                        any = true;
                    }
                }
                if(acum.size() == 0)
                {
                    if(any)
                    {
                        if(sum <= d) ans = max(ans, sum);
                    }
                    else
                    {
                        if(sum <= d)
                        {
                            ans = sum;
                            any = true;
                        }
                    }
                }
                acum.insert(sum);
            }
            else
            {
                if(curo == o)
                {
                    tint auxsum = 0;
                    //cout << " too much odds " << curo << " " << l << " " << r << " " << s[l] << endl;
                    while(l < r and !(s[l] & 1))
                    {
                        auxsum += s[l];
                        l++;                        
                        acum.erase(auxsum);
                    }
                    bool add = (l < r);
                    if(l < r)
                    {
                        auxsum += s[l]; l++;
                        acum.erase(auxsum);
                    }
                    //cout << l << " " << auxsum << " " << add << endl;     
                    set<tint> nacum;
                    sum -= auxsum;

                    fora(e,acum)
                    {
                        nacum.insert(e - auxsum);
                    }

                    acum = nacum;

                    if(add and (max(curo-1,0)+1) <= o)
                    {
                        sum += s[r];
                        set<tint>::iterator it = acum.upper_bound(sum - d - 1ll);
                        if(it != acum.end())
                        {
                            if(any)
                            {
                                ans = max(ans, sum - (*it));
                                if(sum <= d) ans = max(ans, sum);
                            }
                            else
                            {
                                ans = sum - (*it);
                                if(sum <= d) ans = max(ans, sum);
                                any = true;
                            }
                        }
                        if(acum.size() == 0)
                        {
                            if(any)
                            {
                                if(sum <= d) ans = max(ans, sum);
                            }
                            else
                            {
                                if(sum <= d)
                                {
                                    ans = sum;
                                    any = true;
                                }
                            }
                        }
                        acum.insert(sum);
                    }
                    else curo = 0;
                    /*
                    fora(e,acum) cout << e << " ";
                    cout << "fin odds " << sum << endl;
                    */                   
                }
                else
                {
                    curo++;
                    sum += s[r];
                    set<tint>::iterator it = acum.upper_bound(sum - d - 1ll);
                    if(it != acum.end())
                    {
                        if(any)
                        {
                            ans = max(ans, sum - (*it));
                            if(sum <= d) ans = max(ans, sum);
                        }
                        else
                        {
                            ans = sum - (*it);
                            if(sum <= d) ans = max(ans, sum);
                            any = true;
                        }
                    }
                    if(acum.size() == 0)
                    {
                        if(any)
                        {
                            if(sum <= d) ans = max(ans, sum);
                        }
                        else
                        {
                            if(sum <= d)
                            {
                                ans = sum;
                                any = true;
                            }
                        }
                    }
                    acum.insert(sum);
                }
            }
            r++;
            /*
            cout << l << " " << r << " " << curo << " conj " << endl;            
            fora(e,acum) cout << e << " ";
            cout << endl;
            if(any) cout << " ANS " << ans << endl;
            */
        }

        if(any)
            cout << "Case #" << caso << ": " << ans << endl;
        else
            cout << "Case #" << caso << ": " << "IMPOSSIBLE" << endl;
    }

	return 0;
}