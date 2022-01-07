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

bool WIN;
const int WHITE_CONV = 3;
const int BLACK_CONV = 0;
const int N = 4;

char pieces[5] = {'Q','N','B','P','R'};
map<char,int> code;
int W,B,M;

int dx_knight[8] = {-1,-2,-2,-1, 1, 2, 2, 1};
int dy_knight[8] = {-2,-1, 1, 2, 2, 1,-1,-2};

int dx_rook[4] = { 0,-1, 0, 1};
int dy_rook[4] = {-1, 0, 1, 0};

int dx_bishop[4] = {-1,-1, 1, 1};
int dy_bishop[4] = {-1, 1,-1, 1};


inline int get_code(char c, bool white)
{
	int ans = pieces[c];
	if(!white) ans += 5;

	return (ans);
}

inline bool valid(int a, int b)
{
	bool ans = (a >= 0) and (a < N) and (b >= 0) and (b < N);
	return (ans);
}

inline bool is_white(int p) { return (p <= 5 and p >= 1); }
inline bool is_black(int p) { return (p > 5); }
inline bool is_occ(int p) { return (p >= 1); }
inline bool is_enemy(int p, bool white)
{
	if(white) return (is_black(p));
	return is_white(p);
}
inline bool is_mine(int p, bool white)
{
	if(white) return (is_white(p));
	return is_black(p);
}
inline bool is_queen(int p, bool white)
{
	int q = get_code('Q', white);
	return (p == q);
}

struct state
{
	int board[N][N];
	bool white;
	bool lost;

	state()
	{
		forn(i,4) forn(j,4) board[i][j] = 0;
		white = true;
		lost = false;
	}

	void print()
	{
		string players[2] = {"BLACK", "WHITE"};
 		string status[2] = {"NORMAL", "LOST"};

		cout << "PLAYER " << players[white] << endl;
		cout << "GAME STATUS " << status[lost] << endl;

		forn(i,N)
		{
			forn(j,N)
			{
				int pos = board[i][j];
				if(pos == 0) cout << ".";
				else
				{
					pos--;
					if(pos <= 5) cout << pieces[pos];
					else cout << tolower(pieces[pos-5]);
				}
			
			}
			cout << endl;
		}
	}
};

struct movement
{
	int i,j,piece;
	bool kill_queen;

	movement() : i(0), j(0), piece(0), kill_queen(false)
	{}

	movement(int i, int j, int piece, bool kill_queen = false) : i(i), j(j), piece(piece), kill_queen(kill_queen)
	{}

	void print()
	{
		int q = (piece > 5) ? piece - 5 : piece;
		q--;
		string queen = kill_queen ? "YES" : "NO";
		cout << "PIECE " << pieces[q] << endl;
		cout << "POS: " << i << " " << j << endl;
		cout << "CAPTURE QUEEN: " << queen << endl;
	}
};

vector<movement> get_movements(state st, int i, int j)
{
	vector<movement> ans;

	bool white = st.white;
	if(st.board[i][j] == 0) return ans;
	int piece = st.board[i][j];
	bool white_piece = is_white(piece);

	if(white_piece and !white) return ans;
	if(!white_piece and white) return ans;

	if(!white_piece)
		piece -= 5;

	switch(piece)
	{
		case 1:
			{
				// Queen

				forn(k,4)
				{
					int a = i;
					int b = j;
					bool stop = false;
					while(!stop)
					{
						a += dx_rook[k];
						b += dy_rook[k];

						if(!valid(a,b)) stop = true;
						int pos = st.board[a][b];
						if(is_occ(pos))
						{
							stop = true;
							if(is_enemy(pos, white))
							{
								struct movement m(a,b,piece, is_queen(pos,!white));
								ans.pb(m);
							}
						}
						else
						{
							struct movement m(a,b,piece);
							ans.pb(m);
						}
					}
				}

				forn(k,4)
				{
					int a = i;
					int b = j;
					bool stop = false;
					while(!stop)
					{
						a += dx_bishop[k];
						b += dy_bishop[k];

						if(!valid(a,b)) stop = true;
						int pos = st.board[a][b];
						if(is_occ(pos))
						{
							stop = true;
							if(is_enemy(pos, white))
							{
								struct movement m(a,b,piece, is_queen(pos,!white));
								ans.pb(m);
							}
						}
						else
						{
							struct movement m(a,b,piece);
							ans.pb(m);
						}
					}
				}

				break;
			}		
			
		case 2:
			{
				// Knight

				forn(k,8)
				{
					int a = i + dx_knight[k];
					int b = j + dy_knight[k];

					if(!valid(a,b)) continue;
					
					int pos = st.board[a][b];
					if(is_occ(pos))
					{
						if(is_enemy(pos, white))
						{
							struct movement m(a,b,piece, is_queen(pos,!white));
							ans.pb(m);
						}
					}
					else
					{
						struct movement m(a,b,piece);
						ans.pb(m);
					}
				}
				break;	
			}
			
		case 3:
			{
				// Bishop

				forn(k,4)
				{
					int a = i;
					int b = j;
					bool stop = false;
					while(!stop)
					{
						a += dx_bishop[k];
						b += dy_bishop[k];

						if(!valid(a,b)) stop = true;
						int pos = st.board[a][b];
						if(is_occ(pos))
						{
							stop = true;
							if(is_enemy(pos, white))
							{
								struct movement m(a,b,piece, is_queen(pos,!white));
								ans.pb(m);
							}
						}
						else
						{
							struct movement m(a,b,piece);
							ans.pb(m);
						}
					}
				}
				break;	
			}
			
		case 4:
			{
				// Pawn

				int dx = white ? -1 : 1;
				int CONV = white ? WHITE_CONV : BLACK_CONV;

				if(j)
				{
					int diag_left = st.board[i+dx][j-1];
					if(is_occ(diag_left))
					{
						if(is_enemy(diag_left, white))
						{
							struct movement m(i+dx,j-1, piece, is_queen(diag_left,!white));

							if(i+dx == CONV)
							{
								m.piece = get_code('B', white);
								ans.pb(m);
								m.piece = get_code('N', white);
								ans.pb(m);
								m.piece = get_code('R', white);
								ans.pb(m);
							}
							else
							{
								ans.pb(m);	
							}
							
						}
					}
				}
				
				if(j < N)
				{
					int diag_right = st.board[i+dx][j+1];
					if(is_occ(diag_right))
					{
						if(is_enemy(diag_right, white))
						{
							struct movement m(i+dx,j+1, piece, is_queen(diag_right,!white));

							if(i+dx == CONV)
							{
								m.piece = get_code('B', white);
								ans.pb(m);
								m.piece = get_code('N', white);
								ans.pb(m);
								m.piece = get_code('R', white);
								ans.pb(m);
							}
							else
							{
								ans.pb(m);
							}
						}
					}
				}
				
				int fol = st.board[i+dx][j];

				if(!is_occ(fol))
				{				
					struct movement m(i+dx,j, piece);

					if(i+dx == CONV)
					{
						m.piece = get_code('B', white);
						ans.pb(m);
						m.piece = get_code('N', white);
						ans.pb(m);
						m.piece = get_code('R', white);
						ans.pb(m);
					}
					else
					{
						ans.pb(m);
					}
				}

				break;
			}
		case 5:
			{
				// Rook

				forn(k,4)
				{
					int a = i;
					int b = j;
					bool stop = false;
					while(!stop)
					{
						a += dx_rook[k];
						b += dy_rook[k];

						if(!valid(a,b)) stop = true;
						int pos = st.board[a][b];
						if(is_occ(pos))
						{
							stop = true;
							if(is_enemy(pos, white))
							{
								struct movement m(a,b,piece, is_queen(pos,!white));
								ans.pb(m);
							}
						}
						else
						{
							struct movement m(a,b,piece);
							ans.pb(m);
						}
					}
				}
				break;
			}			
		default:
			break;
	}

	return ans;
}

void bt(int turn, state cur)
{
	cur.print();
	if(turn > M) return;
	if(cur.lost) return;

	bool new_player = !cur.white;

	forn(i,N)
	{
		forn(j,N)
		{
			int piece = cur.board[i][j];

			if(is_mine(piece, cur.white))
			{
				vector<movement> movements = get_movements(cur, i, j);

				fora(m, movements)
				{
					cur.white = new_player;
					int prev_piece = cur.board[m.i][m.j];
					cur.board[i][j] = m.piece;
					cur.board[i][j] = 0;
					cur.lost = m.kill_queen;
					bt(turn+1,cur);
					cur.board[i][j] = piece;
					cur.board[m.i][m.j] = prev_piece;
					cur.white = !new_player;
					cur.lost = false;
				}
			}
		}
	}
}

int main()
{
	forn(i,5) code[pieces[i]] = i+1;

	int g; cin >> g;
	char c,a; int b;

	forn(caso, g)
	{
		cin >> W >> B >> M;
		struct state st;

		forn(i,W)
		{
			cin >> c >> a >> b;
			b--; b = N - b;
			int A = (int)(a - 'A');
			st.board[b][A] = get_code(c, true);
		}
		cout << "read white" << endl;
		forn(i,B)
		{
			cin >> c >> a >> b;
			b--;
			int A = (int)(a - 'A');
			st.board[b][A] = get_code(c, false);	
		}
		cout << "read black" << endl;
		bt(1,st);
	}

	return 0;
}