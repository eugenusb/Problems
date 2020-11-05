#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sq(a) (a)*(a)

using namespace std;

typedef long long int tint;
typedef pair<tint,tint> punto;

pair< punto, tint > monument[4100];
pair< punto, tint > aux[4100];
punto center;


int sq_dist(punto a, punto b) 
{ 
    return sq(a.F - b.F) + sq(a.S - b.S);
}

bool menor(punto a, punto b)
{
	if (a.F - center.F >= 0 and b.F - center.F < 0)
        return true;
    if (a.F - center.F < 0 and b.F - center.F >= 0)
        return false;
    if (a.F - center.F == 0 and b.F - center.F == 0)
    {
        if (a.S - center.S >= 0 or b.S - center.S >= 0)
            return a.S > b.S;
        return b.S > a.S;
    }

    tint det = (a.F - center.F) * (b.S - center.S) - (b.F - center.F) * (a.S - center.S);
    if (det > 0)
        return true;
    if (det < 0)
        return false;
    
    return (sq_dist(center, b) >= sq_dist(center, a));
}

bool clock(punto a, punto b)
{
	tint det = (a.F - center.F) * (b.S - center.S) - (b.F - center.F) * (a.S - center.S);
    
    return (det > 0);
}

bool compare(pair< punto, tint> m1, pair< punto, tint> m2)
{
	punto a = m1.F; punto b = m2.F;

	return (menor(a,b));
}


int main()
{
	int n;
	cin >> n;
	tint tot = 0;

	forn(i,n)
	{
		cin >> monument[i].F.F >> monument[i].F.S >> monument[i].S;
		aux[i] = monument[i];
		tot += monument[i].S;
	}
	tint ans = tot;

	forn(i,n)
	{
		center = aux[i].F;
		tint cost_center = aux[i].S;
		
		//cout << "CENTRO " << center.F << " " << center.S << endl;

		forn(j,n)
		{
			if(monument[j].F == center)
			{
				swap(monument[0], monument[j]);
			}
		}
		sort(monument+1, monument+n, compare);

		punto opuesto = mp(-monument[1].F.F + 2*center.F, -monument[1].F.S + 2*center.S);

		tint cnd = 0;
		tint line = cost_center + monument[1].S; 
		int j = 2;
		
		while(j < n and menor(monument[j].F, opuesto))
		{
			cnd += monument[j].S;
			j++;
		}

		int l = 2; int r = j == n ? 1 : j;
		ans = min(ans, abs(tot - 2 * cnd - line));
		int cant = 1;

		while(cant < n)
		{
			// cual esta mas cerca, l o r?
			punto prox = monument[l].F;
			//cout << "indices " << l << " " << r << endl;
			opuesto = mp(2 * center.F - prox.F, 2 * center.S - prox.S);

			if(clock(opuesto, monument[r].F))
			{
				// l esta mas cerca
				//cout << prox.F << " " << prox.S << endl;
				line -= (monument[l-1].S - monument[l].S);
				l++;
			}
			else
			{
				// r esta mas cerca
				//cout << monument[r].F.F << " " << monument[r].F.S << endl;
				cnd += monument[r-1].S;
				line -= (monument[r-1].S - monument[r].S);
				r++;
				if(r == n) r = 1;
			}
			cant++;
			//cout << "ANS " << cnd << " " << line << " " << tot - 2 * cnd - line << endl;
			ans = min(ans, abs(tot - cost_center - 2 * cnd - line));
		}

		/*
		forn(j,n)
		{
			cout << monument[j].F.F << " " << monument[j].F.S << endl;
		}
		cout << endl << endl;
		*/
	}

	cout << ans << endl;

	return 0;
}