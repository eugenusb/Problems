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

int tab[110][110];

int main()
{
	int n; cin >> n;

	vector<par> one_pos;
	vector<par> two_pos;
	forsn(i,1,n+1)
	{
		forsn(j,1,n+1)
		{
			tab[i][j] = -1;
			if((i + j) & 1)
			{
				two_pos.pb(mp(i,j));
			}
			else
			{
				one_pos.pb(mp(i,j));
			}
		}		
	}

	int a;
	int one, two;
	cin >> a;

	forsn(i,1,4)
	{
		if(i != a)
		{
			one = i;
			break;
		}
	}
	int one_index = 0;
	int two_index = 0;
	int tot_ones = (int) one_pos.size();
	int tot_twos = (int) two_pos.size();

	cout << one << " " << one_pos[one_index].F << " " << one_pos[one_index].S << endl;
	one_index++;
	cin >> a;

	forsn(i,1,4)
	{
		if(i != a and i != one)
		{
			two = i;
			break;
		}
	}
	cout << two << " " << two_pos[two_index].F << " " << two_pos[two_index].S << endl;
	two_index++;

	forn(move,n*n-2)
	{
		cin >> a;
		if(a == one)
		{
			if(two_index < tot_twos)
			{
				cout << two << " " << two_pos[two_index].F << " " << two_pos[two_index].S << endl;
				two_index++;
			}
			else
			{
				// ya gane
				int b;
				forsn(i,1,4)
				{
					if(i != a and i != two)
					{
						b = i;
						break;
					}
				}
				cout << b << " " << one_pos[one_index].F << " " << one_pos[one_index].S << endl;
				one_index++;
			}
		}
		else
		{
			if(one_index < tot_ones)
			{
				cout << one << " " << one_pos[one_index].F << " " << one_pos[one_index].S << endl;
				one_index++;
			}
			else
			{
				// ya gane
				int b;
				forsn(i,1,4)
				{
					if(i != a and i != one)
					{
						b = i;
						break;
					}
				}
				cout << b << " " << two_pos[two_index].F << " " << two_pos[two_index].S << endl;
				two_index++;
			}
		}
	}

	return 0;
}