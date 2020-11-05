#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define R real
#define I imag
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

struct dice
{
	int m;
    int groups[55];
    dice(int m): m(m)
    {
        forn(i,55) groups[i] = 0;
    }
};

bool operator<(const dice& d1, const dice& d2) 
{ 
    int m = d1.m;

    forn(i,m)
    {
    	if(d1.groups[i] != d2.groups[i])
        {
            return (d1.groups[i] < d2.groups[i]);
        }
    }

    return (false);
}

map<dice, double> dp;
map<dice, double> pr;

int main()
{
    int t; cin >> t;
    int n,m,k;

    forsn(caso,1,t+1)
    {
        dp.clear(); pr.clear();
        cin >> n >> m >> k;
        dice goal(m);
        int tot = 0;
        forn(i,k)
        {
            cin >> goal.groups[i];
            tot += goal.groups[i];
        }
        sort(goal.groups, goal.groups+55);
        reverse(goal.groups, goal.groups+55);

        // tot pasos
        queue<dice> Q;
        dice initial(m);
        initial.groups[0] = 1;
        Q.push(initial);

        while(!Q.empty())
        {
            dice cur = Q.front();
        }
    }

    return 0;
}