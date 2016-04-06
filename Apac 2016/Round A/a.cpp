#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2(ll x){
	if(x==0) return 1LL;
	ll half = pow2(x/2);
	ll ans = half;
	ans *= half;
	if(x%2==1){
		ans*=2;
	}
	return ans;
}


int findChar(ll k, ll n, bool op){
 	
	ll power = pow2(n);
	if(k<power){
		return findChar(k, n-1, op);
	}
	else if (k>power){
		return findChar(pow2(n+1)-k, n-1, !op);
	}
	else{
		return op;
	}
}

int main(){
	ifstream inp("./aLarge.in");
	ofstream out("./aLarge.out");
	int t;
	inp>>t;
	for(int a = 1; a<=t; a++){
		out<<"Case #"<<a<<": ";
		ll k;
		inp>>k;
		out<<findChar(k, 60, false)<<endl;
	}
}