#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;
ll arr[110][110];
ll INF = 100000000000000000;
vector< pair< pair<ll, ll> , ll> > edges;
int main(){

	ifstream inp("./cLarge.in");
	ofstream out ("./cLarge.out");
	
	ll t;
	inp>>t;
	for(ll a=1; a<=t; a++){
		out<<"Case #"<<a<<":"<<endl;

		ll n,m;
		inp>>n>>m;
		for(ll i=0; i<n; i++){
			for(ll j=0; j<n; j++){
				if(i==j)arr[i][j]=0;
				else arr[i][j]=INF;
			}
		}
		edges.clear();
		for(ll i=0; i<m; i++){
			ll u,v,c;
			inp>>u>>v>>c;
			arr[u][v] = min(arr[u][v],c);
			arr[v][u] = min(arr[v][u],c);
			edges.pb(mp(mp(u,v),c));
		}

		for(ll k=0; k<n ; k++){
			for(ll i=0; i<n; i++){
				for(ll j=0; j<n; j++){
					arr[i][j] = min(arr[i][j], arr[i][k]+ arr[k][j]);
				}
			}
		}

		for(ll k=0; k<m; k++){
			ll x, y, w;
			x = edges[k].F.F;
			y = edges[k].F.S;
			w = edges[k].S;
			bool check = false;
			for(ll i=0; i<n && (!check); i++){
				for(ll j=0; j<n; j++){
					if(arr[i][j]==(arr[i][x]+w+arr[y][j])){
						check = true;
						break;
					}
					if(arr[i][j]==(arr[i][y]+w+arr[x][j])){
						check = true;
						break;
					}				
				}
			}
			if(!check){
				out<<k<<endl;
			}
		}
	}
}