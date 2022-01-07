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

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1};

int r,c;

bool valid(int a, int b)
{
	bool ans = (a >= 0) and (a < r) and (b >= 0) and (b < c);

	return ans;
}

int main()
{
	int t; cin >> t;

	forsn(caso, 1, t+1)
	{
		cin >> r >> c;
		vector< vector<int> > S(r, vector<int>(c));
		vector< vector<int> > suma(r, vector<int>(c));
		vector< vector<int> > cant(r, vector<int>(c));
		vector< vector<int> > up(r, vector<int>(c));
		vector< vector<int> > down(r, vector<int>(c));
		vector< vector<int> > left(r, vector<int>(c));
		vector< vector<int> > right(r, vector<int>(c));
		vector< vector<int> > state(r, vector<int>(c,0));

		tint tot = 0ll;
		forn(i,r)
		{
			forn(j,c)
			{
				cin >> S[i][j];
				tot += S[i][j];
				up[i][j] = i-1;
				down[i][j] = i+1;
				left[i][j] = j-1;
				right[i][j] = j+1;
			}
		}

		queue<par> check;

		forn(i,r)
		{
			forn(j,c)
			{
				int cnt = 0;
				int sum = 0;

				forn(k,4)
				{
					int a = i + dx[k];
					int b = j + dy[k];

					if(valid(a,b))
					{
						cnt++;
						sum += S[a][b];
					}	
				}

				suma[i][j] = sum;
				cant[i][j] = cnt;

				check.push({i,j});
			}
		}

		tint ans = 0;
		bool turn = true;
		int ind_turn = 1;
		while(turn)
		{
			turn = false;
			vector<par> elim;

			//cout << "CHECK " << endl;
			while(!check.empty())
			{
				par p = check.front(); check.pop();
				int a = p.first; int b = p.second;
				//cout << "(" << a << " " << b << ")" << "; ";
				if(state[a][b] == -1) continue;
				if(S[a][b] * cant[a][b] < suma[a][b])
				{
					elim.pb({a,b});
				}				
			}
			//cout << endl;
			//cout << "TOT " << tot << endl;
			ans += tot;

			if(!elim.empty()) turn = true;

			//cout << "ELIM " << endl;
			fora(p, elim)
			{
				int a = p.first; int b = p.second;
				//cout << "(" << a << " " << b << ")" << "; ";
				tot -= S[a][b];
				state[a][b] = -1;

				int lb = left[a][b];
				int rb = right[a][b];
				int upa = up[a][b];
				int da = down[a][b];

				if(valid(a,lb))
				{
					right[a][lb] = rb;
					if(state[a][lb] != -1)
					{
						if(state[a][lb] != ind_turn)
						{
							check.push({a,lb});
							state[a][lb] = ind_turn;
						}
						suma[a][lb] -= S[a][b];
						cant[a][lb]--;

						// change right of (a,lb)
						
						if(valid(a,rb) and state[a][rb] != -1)
						{
							cant[a][lb]++;
							suma[a][lb] += S[a][rb];
						}
					}					
				}
				
				if(valid(a,rb))
				{
					left[a][rb] = lb;
					if(state[a][rb] != -1)
					{
						if(state[a][rb] != ind_turn)
						{
							check.push({a,rb});
							state[a][rb] = ind_turn;
						}
						suma[a][rb] -= S[a][b];
						cant[a][rb]--;

						// change left of (a,rb)
						
						if(valid(a,lb) and state[a][lb] != -1)
						{
							cant[a][rb]++;
							suma[a][rb] += S[a][lb];
						}
					}
				}
				
				if(valid(upa, b))
				{
					down[upa][b] = da;
					if(state[upa][b] != -1)
					{
						if(state[upa][b] != ind_turn)
						{
							check.push({upa,b});
							state[upa][b] = ind_turn;	
						}
						suma[upa][b] -= S[a][b];
						cant[upa][b]--;

						// change down of (upa,b)
						
						if(valid(da,b) and state[da][b] != -1)
						{
							cant[upa][b]++;
							suma[upa][b] += S[da][b];
						}
					}
				}

				if(valid(da,b))
				{
					up[da][b] = upa;
					if(state[da][b] != -1)
					{
						if(state[da][b] != ind_turn)
						{
							check.push({da,b});
							state[da][b] = ind_turn;
						}
						suma[da][b] -= S[a][b];
						cant[da][b]--;

						// change up of (da,b)
						
						if(valid(upa,b) and state[upa][b] != -1)
						{
							cant[da][b]++;
							suma[da][b] += S[upa][b];
						}
					}
				}
			}

			//cout << endl;
			ind_turn++;
		}

		/*
		forn(i,r)
		{
			forn(j,c)
			{
				cout << up[i][j] << " ";
			}
			cout << endl;
		}

		forn(i,r)
		{
			forn(j,c)
			{
				cout << down[i][j] << " ";
			}
			cout << endl;
		}

		forn(i,r)
		{
			forn(j,c)
			{
				cout << left[i][j] << " ";
			}
			cout << endl;
		}

		forn(i,r)
		{
			forn(j,c)
			{
				cout << right[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}