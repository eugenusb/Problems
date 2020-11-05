#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define fora(e,v) for(auto e : v)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second

double sumaEnRank(vpi& valoresRank, int entro, int salgo){
  double res = 0.0;
  int i = 0;
  while(i < valoresRank.size() && valoresRank[i].F < entro) i++;
  i--;
  i = max(0,i);
  while(i < valoresRank.size()){
    if(valoresRank[i].F >= salgo) break;
    if(i < valoresRank.size()-1){
      int izq = max(valoresRank[i].F, entro);
      int der = min(valoresRank[i+1].F, salgo);
      res += (der-izq)*valoresRank[i].S;
    }
    else{
      int izq = max(valoresRank[i].F, entro);
      int der = salgo;
      res += (der-izq)*valoresRank[i].S;
    }
    i++;
  }
  return res;
}

double actualizarPuntosPorPersona(vpi& persona, map<int,vpi>& rankPorPunto, int w){
  double res = 0.0;
  F0(i, persona.size()){
    int entro = persona[i].S; //mayor o igual
    int salgo = w; //menor estricto
    int puntaje = persona[i].F;
    if(i != persona.size()-1){
      salgo = persona[i+1].S;
    }
    res += sumaEnRank(rankPorPunto[puntaje], entro, salgo);
  }
  return res;
}

int main(){
  int n, w; cin>>n>>w;
  vector<vpi> persona(n+1, vpi(1,mp(0,0))); //entré en el momento S al puntaje F
  map<int,vpi> rankPorPunto; //lista de (momento, rank)
  vector<double> PuntosPorPersona(n+1); //respuesta
  rankPorPunto[0].pb(mp(0,1));
  F1(i,w){
    int aux; cin>>aux;
    int k;
    F0(j,aux){
      cin>>k;
      int puntaje = persona[k].back().F;
      int rank = rankPorPunto[puntaje].back().S;
      if(rankPorPunto.count(puntaje+1)==0) rankPorPunto[puntaje+1].pb(mp(i, rank));
      rankPorPunto[puntaje].pb(mp(i,rank+1));
      persona[k].pb(mp(puntaje+1, i));
    }
  }
  F1(i,n){
    PuntosPorPersona[i] = actualizarPuntosPorPersona(persona[i], rankPorPunto, w);
    cout<<PuntosPorPersona[i]<<'\n';
  }

}
