#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ifstream inp("./bSmall.in");
	ofstream out ("./bSmall.out");
	ll t;
	inp>>t;
	//cout<<"yo bbwc";
	for(int i=1; i<=t; i++){
		out<<"Case #"<<i<<":"<<endl;
		ll n, m;
		inp>>n>>m;
		vector<ll> arr;
		for(int j=0; j<n; j++){
			ll x;
			inp>>x;
			//cout<<x<<endl;
			arr.push_back(x);
		}

		ll pre[n+1];
		ll suf[n+1];
		pre[0] =1, suf[n]=1;
		for(int j=1; j<=n; j++){
			pre[j] = pre[j-1]*arr[j-1];
			cout<<"pre[j] at j= "<<j<<" is "<<pre[j]<<endl;
		}
		for(int j=n-1; n>=0; n--){
			suf[j] =suf[j+1]*arr[j];
		}
		ll prod = pre[n];
		for(int j=0; j<m; j++){
			ll l,r;
			inp>>l>>r;
			cout<<"prod is "<<prod<<endl;
			double nume = prod;
			double denome = pre[l]*suf[r+1];
			double req = nume/denome;
			ll num = r-l+1;
			cout<<"req is "<<req<<endl;
			cout<<"num is "<<num<<endl;
			double ans = pow(req, (1/num));
			//cout<<ans
			out<<std::setprecision(9)<<ans<<endl; 
		}
	}
}