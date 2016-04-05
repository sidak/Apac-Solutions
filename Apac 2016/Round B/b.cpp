#include<bits/stdc++.h>
/*
struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};
*/
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;

ll calcGcd(ll a, ll b){
	if(b==0) return a;
	else return calcGcd(b, a%b);
}

int main(){
	ifstream inp("./bSmall.in");
	ofstream out("./bSmall1.out");
	
	ll t;
	
	inp>>t;
	for(ll a = 1; a<=t; a++){
		out<<"Case #"<<a<<":"<<endl;
		ll n1, n2, n3;
		inp>>n1>>n2>>n3;
		vector<ll> arr1, arr2, arr3;
		for(int i=0; i<n1; i++){
			ll x;
			inp>>x;
			arr1.pb(x);
		}
		for(int i=0; i<n2; i++){
			ll x;
			inp>>x;
			arr2.pb(x);
		}
		for(int i=0; i<n3; i++){
			ll x;
			inp>>x;
			arr3.pb(x);
		}
		// if unordered_map is needed for pair of ll's and bool, uncomment the lines before namespace std and after includes
		//unordered_map < pair< ll,ll > , bool , pairhash> outer;
		map < pair< ll,ll > , bool> outer;
		for(int i=0; i<n1; i++){
			for(int j=0; j<n3; j++){
				ll gcd = calcGcd(arr1[i], arr3[j]);
				ll x = arr1[i]/gcd;
				ll y = arr3[j]/gcd;
				outer[mp(x,y)] = true;	
			}
		}

		ll m;
		inp>>m;
		for(int i=0; i<m; i++){
			ll p,q;
			inp>>p>>q;
			bool flag = false;
			for(int j=0; j<n2 && (!flag); j++){
				for(int k =0; k<n2; k++){
					if(k==j) continue;

					
					ll x = arr2[j] * q;
					ll y = arr2[k] * p;
					ll gcd = calcGcd(x, y);

					x/= gcd;
					y/=gcd;

					if(outer.find(mp(y,x))!=outer.end()){
						flag = true;
						break;
					}

				}
			}
			if(flag) out<<"Yes"<<endl;
			else out<<"No"<<endl;
		}
	}
}