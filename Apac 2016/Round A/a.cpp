#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2(ll x){
	ll half = pow2(x/2);
	ll ans = half;
	ans *= half;
	if(x%2==1){
		ans*=2;
	}
	return ans;
}

ll bs(ll x, ll l, ll r){
	while(l<=r){
		
	}
}

int findChar(ll k, ll n, bool op){

	if()
	ll prevExp = bs(k, 0, n);
	ll prev = pow2(prevExp) - 1;
	ll idx = k - prev -1 ;
	
	// if prevExp == 0
	ll left = pow2(prevExp-1) -1 ;
	if(idx<=left){
		return findChar(k, prevExp, op);
	}
	else if (idx == (left+1)){
		if(op){
			return 1;
		}
		else return 0;
	}
	else{
		return findChar(k-left -1, prevExp, !op);
	}
}

int main(){
	int t;
	for(int a = 1; a<=t; a++){
		cout<<"Case #"<<a<<":"<<endl;
		ll k;
		cin>>k;
		cout<<findChar(k, 60, false)<<endl;
	}
}