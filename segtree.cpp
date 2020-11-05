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

tint a[200100];
tint st_alt[4*200010];
tint st_coef[4*200010];


void init(int node, int i, int j)
{
	if(j - i == 1)
	{
		st_coef[node] = a[i];
		st_alt[node] = a[i];
		//cout << i << " " << j << " node " << node << " alt " << st_alt[node] << endl;
		//cout << i << " " << j << " node " << node << " coef " << st_coef[node] << endl;
		return;
	}

	int m = (i + j) / 2;
	init(2*node,i,m);
	init(2*node+1,m,j);

	int sg = (m - i) & 1 ? -1 : 1;
	st_alt[node] = st_alt[2*node] + sg * st_alt[2*node+1];
	st_coef[node] = st_coef[2*node] + sg * st_coef[2*node+1] + sg * (m - i) * st_alt[2*node+1];

	//cout << i << " " << j << " node " << node << " alt " << st_alt[node] << endl;
	//cout << i << " " << j << " node " << node << " coef " << st_coef[node] << endl;

	return;
}

void upd_alt(int node, int i, int j, int k, int v)
{
	if(j <= k) return;
	if(i > k) return;

	if(j - i == 1)
	{
		//st_coef[node] = a[i];
		a[i] = v;
		st_alt[node] = a[i];
		return; //(a[i]);
	}

	int m = (i + j) / 2;
	if(k < m) upd_alt(2*node,i,m,k,v);
	else upd_alt(2*node+1,m,j,k,v);

	int sg = (m - i) & 1 ? -1 : 1;
	st_alt[node] = st_alt[2*node] + sg * st_alt[2*node+1];
	//return (st_alt[node]);
}

void upd_coef(int node, int i, int j, int k, int v)
{
	if(j <= k) return;
	if(i > k) return;

	if(j - i == 1)
	{
		a[i] = v;
		st_coef[node] = a[i];		
		return; //(a[i]);
	}

	int m = (i + j) / 2;
	if(k < m) upd_coef(2*node,i,m,k,v);
	else upd_coef(2*node+1,m,j,k,v);

	int sg = (m - i) & 1 ? -1 : 1;
	
	st_coef[node] = st_coef[2*node] + sg * st_coef[2*node+1] + sg * (m - i) * st_alt[2*node+1];

	//return (st_coef[node]);
}

par query(int node, int i, int j, int l, int r)
{
	if(j <= l) return mp(0,0);
	if(i >= r) return mp(0,0);

	if(l <= i and j <= r)
	{
		//cout << i << " " << j << " " << l << " " << r << " " << st_coef[node] << " " << st_alt[node] << endl;
		return (mp(st_coef[node], st_alt[node]));
	}

	int m = (i + j) / 2;
	par left = query(2*node,i,m,l,r);
	par right = query(2*node+1,m,j,l,r);

	int sg = (min(r,m) - max(i,l)) & 1 ? -1 : 1;
	
	par ans;
	if(l < m)
	{
		ans.F = left.F + sg * right.F + sg * (min(r,m) - max(i,l)) * right.S;
		ans.S = left.S + sg * right.S;
	}
	else
	{
		ans = right;
	}
	/*
	cout << i << " " << m << " " << l << " " << r <<  " left " << left.F << " " << left.S << endl;
	cout << m << " " << j << " " << l << " " << r << " right " << right.F << " " << right.S << endl;
	cout << i << " " << j << " answer " << ans.F << " " << ans.S << endl;
	*/
	return (ans);
}

int main()
{
	int t;
	cin >> t;
	int n,q;

    forsn(caso,1,t+1)
    {
    	cin >> n >> q;
    	forn(i,n) cin >> a[i];
    	
    	init(1,0,n);
    	tint ans = 0;

    	forn(i,q)
    	{
    		char id; int a,b;
    		cin >> id >> a >> b;

    		if(id == 'Q')
    		{
    			tint s = query(1,0,n,a-1,b).F;
    			//cout << a << " " << b << " : " << s << endl;
    			ans += s;
    		}
    		else
    		{
    			// id == 'U'
    			upd_alt(1,0,n,a-1,b);
    			upd_coef(1,0,n,a-1,b);
    		}
    	}
        cout << "Case #" << caso << ": " << ans << endl;
    }

    return 0;
}