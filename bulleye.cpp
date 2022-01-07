#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < (int)(n); i++)
#define fora(e,v) for(auto e : v)
#define pb push_back
#define mp make_pair
#define R real
#define I imag
#define sq(a) (a)*(a)
 
using namespace std;
 
typedef long long int tint;
typedef pair<int,int> par;

int LIM = (int)(1e9);
string verdict;
int xo,yo;

std::random_device random_dev;
std::mt19937 random_engine(random_dev());
std::uniform_int_distribution<int> distribution(-LIM, LIM);

void solve()
{	
	while(true)
	{
		xo = distribution(random_engine);
		yo = distribution(random_engine);
		//cerr << xo << " " << yo << endl;
		cout << xo << " " << yo << endl;
		cin >> verdict;
		//cerr << verdict << endl;
		if(verdict == "CENTER")
		{
			return;
		}
		if(verdict == "HIT")
		{
			break;
		}
	}

	// binary search left and right
	int right, left;
	
	int hi = LIM; int lo = xo;

	cout << LIM << " " << yo << endl;
	//cerr << LIM << " " << yo << endl;	
	cin >> verdict;
	//cerr << verdict << endl;
	if(verdict == "CENTER")
		return;

	if(verdict == "HIT")
	{
		right = LIM;
	}	
	else
	{
		while(hi - lo > 1)
		{
			int m = (hi + lo) / 2;

			cout << m << " " << yo << endl;
			//cerr << m << " " << yo << endl;
			cin >> verdict;
			//cerr << verdict << endl;
			if(verdict == "CENTER")
				return;

			if(verdict == "HIT")
			{
				lo = m;
			}
			else hi = m;
		}

		right = lo;
	}

	hi = xo; lo = -LIM;
	
	cout << -LIM << " " << yo << endl;
	//cerr << -LIM << " " << yo << endl;
	cin >> verdict;
	//cerr << verdict << endl;
	if(verdict == "CENTER")
		return;

	if(verdict == "HIT")
	{
		left = -LIM;
	}
	else
	{
		while(hi - lo > 1)
		{
			int m = (hi + lo) / 2;

			cout << m << " " << yo << endl;
			//cerr << m << " " << yo << endl;
			cin >> verdict;
			//cerr << verdict << endl;
			if(verdict == "CENTER")
				return;

			if(verdict == "HIT")
			{
				hi = m;
			}
			else lo = m;
		}

		left = hi;	
	}

	int center_x = (right+left) / 2;

	// binary search center_y
	int top, bot;

	hi = LIM; lo = yo;
	
	cout << center_x << " " << LIM << endl;
	//cerr << center_x << " " << LIM << endl;
	cin >> verdict;
	//cerr << verdict << endl;
	if(verdict == "CENTER")
		return;
	if(verdict == "HIT")
	{
		top = LIM;
	}
	else
	{
		while(hi - lo > 1)
		{
			int m = (hi + lo) / 2;

			cout << center_x << " " << m << endl;
			//cerr << center_x << " " << m << endl;
			cin >> verdict;
			//cerr << verdict << endl;
			if(verdict == "CENTER")
				return;

			if(verdict == "HIT")
			{
				lo = m;
			}
			else hi = m;
		}

		top = lo;
	}

	hi = yo; lo = -LIM;
	cout << center_x << " " << -LIM << endl;
	//cerr << center_x << " " << -LIM << endl;
	cin >> verdict;
	//cerr << verdict << endl;
	if(verdict == "CENTER")
		return;

	if(verdict == "HIT")
	{
		bot = -LIM;
	}
	else
	{
		while(hi - lo > 1)
		{
			int m = (hi + lo) / 2;

			cout << center_x << " " << m << endl;
			//cerr << center_x << " " << m << endl;
			cin >> verdict;
			//cerr << verdict << endl;
			if(verdict == "CENTER")
				return;

			if(verdict == "HIT")
			{
				hi = m;
			}
			else lo = m;
		}

		bot = hi;
	}

	int center_y = (top + bot) / 2;

	//cerr << "MY CENTER " << center_x << " " << center_y << endl;

	for(int dx = -1; dx <= 1; dx++)
	{
		for(int dy = -1; dy <= 1; dy++)
		{
			cout << center_x + dx << " " << center_y + dy << endl;
			//cerr << center_x + dx << " " << center_y + dy << endl;
			cin >> verdict;
			//cerr << verdict << endl;
			if(verdict == "CENTER")
				return;
		}
	}
}

int main()
{
	int t,a,b; cin >> t >> a >> b;

	forn(caso,t)
	{
		solve();
	}

	return 0;
}