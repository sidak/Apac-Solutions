#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ifstream inp("./bLarge.in");
	ofstream out ("./bLarge.out");
	ll t;
	inp>>t;
	for(int i=1; i<=t; i++){
		out<<"Case #"<<i<<":"<<endl;
		ll n, m;
		inp>>n>>m;
		vector<ll> arr;
		for(int j=0; j<n; j++){
			ll x;
			inp>>x;
			arr.push_back(x);
		}

		for(int j=0; j<m; j++){
			ll l,r;
			inp>>l>>r;
			double num = r-l+1; // if ll instead of double, then power will always be 0
			double ans = 1;

			for(ll k =l; k<=r; k++){
				// there is no need to multiply fully
				ans *= pow(arr[k],(1/num)) ;
			}
						
			out.precision(9);
			out<<fixed<<ans<<endl; 
			
			// This following alone won't work
			//out<<setprecision(9)<<endl;
		}
	}
}