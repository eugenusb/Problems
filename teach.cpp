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


vector<string> subset(string a)
{	
	string cur = "";
	vector<string> elem;

	forn(i,a.size())
	{
		if(a[i] == '.')
		{
			elem.pb(cur);
			cur = "";
		}
		else cur += a[i];
	}

	int k = elem.size();
	vector<string> ans;

	forsn(mask,1,(1<<k)-1)
	{
		string subs = "";
		forn(i,k)
		{
			if(mask & (1<<i))
			{
				subs += elem[i];
				subs += ".";
			}
		}
		ans.pb(subs);
	}

	return (ans);
}

int main()
{
	int t; cin >> t;
	tint n;
	int s,c;
	string word, num;

    forsn(caso,1,t+1)
    {
    	map<string,int> code;
    	cin >> n >> s;

    	forn(i,n)
    	{
    		cin >> c;
    		word = "";
    		vector<string> aux;
    		forn(j,c)
    		{
    			cin >> num;
    			aux.pb(num);
    		}
    		sort(aux.begin(), aux.end());
    		forn(j,c)
    		{    			
    			word += aux[j];
    			word += ".";
    		}
    		if(code.find(word) == code.end()) code[word] = 1;
    		else code[word]++;
    	}

    	tint ans = (n*n) - n;

    	map<string,int>::iterator it;

    	for(it = code.begin(); it != code.end(); it++)
    	{
    		tint k = (it->S);
    		ans -= (k * (k - 1));
    		word = (it->F);

    		//cout << "WORD " << word << endl;
    		vector<string> sub = subset(word);
    		forn(l, sub.size())
    		{
    			string w = sub[l];
    			//cout << w << endl;
    			if(code.find(w) != code.end()) ans -= k * code[w];
    		}
    	}

        cout << "Case #" << caso << ": " << ans << endl;
    }

	return 0;
}