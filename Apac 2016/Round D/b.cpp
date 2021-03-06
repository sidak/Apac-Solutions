
#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define ppb pop_back
#define mp(x,y) make_pair((x),(y))
//#define sd(n) scanf("%d" , &n);
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define maX(a,b)   ( (a) > (b) ? (a) : (b))
#define miN(a,b)   ( (a) < (b) ? (a) : (b))
#define bitcount   __builtin_popcount
#define mset(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forit(it, s) for(typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it) 
#define F first
#define S second
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define LEN(X) strlen(X)
#define iOS ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs;
typedef long double ld;
typedef  long long ll;
typedef unsigned long long ull;
string NumberToString ( ll Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


ll StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	ll result;
	return ss >> result ? result : 0;
}

void solve(){
	
}
#ifdef DEBUGIT
  #define DEBUG(X) cerr << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << X << endl
#else
  #define DEBUG(X) (void)0
#endif

int vel[1010];
pii pt[110];
int n,m,q;
ll INF = 1e15; 
ll myabs(ll x){
	if(x<0) return -x;
	else return x;
}
bool isSuitable(ll val){
	ll total_cost = 0;
	for(int i=0; i<n; i++){
		ll min_cost = INF;
		if(pt[i].F==0)continue;
		for(int j=0; j<m; j++){
			if(pt[i].F>0 && vel[j]<0){
				if((pt[i].F + val*vel[j])<=0){
					min_cost = min(min_cost, myabs(j-pt[i].S));
				}
			}
			else if(pt[i].F<0 && vel[j]>0){
				if((pt[i].F + val*vel[j])>=0){
					min_cost = min(min_cost, myabs(j-pt[i].S));
				}
			}
		}
		if(min_cost==INF) return false;
		total_cost+= min_cost;
		
	}
	if(total_cost>q){
			return false;
	}
	else return true;
}
int binSearch(){
	int low = 0;
	int high = 20000;
	int  mid ;
	while(low<high){
		mid = low + (high-low)/2;
		if(isSuitable(mid)){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}
	if(isSuitable(low)){
		return low;
	}
	return -1;
}
int main(){
	ifstream inp("./b_large.in");
	ofstream out("./b_large.out");
	int t;
	inp>>t;
	for(int a =1 ;a <=t; a++){
		inp>>n>>m>>q;
		for(int i=0; i<m; i++){
			inp>>vel[i];
		}
		for(int i=0; i<n; i++){
			int x, y;
			inp>>x>>y;
			pt[i]=mp(x,y);
		}
		int ans = binSearch();
		if(ans!=-1) out<<"Case #"<<a<<": "<<ans<<endl;
		else out<<"Case #"<<a<<": "<<"IMPOSSIBLE"<<endl;
	}	
}
