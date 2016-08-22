
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
int check_ans(ll x, vpll v){
	for(int i=0; i<v.size(); i++){
		ll calc = (100*v[i].S)/x ;
		cout<<"calc is "<<calc<<endl;
		if(calc == 0) return -1;
		else if(v[i].F>calc){
			return 1;
		}
		else if (v[i].F<calc) return -1;
		
	}
	return 0;
}
ll inf = 1e16;
int main(){
	ifstream inp("./b_large.in");
	ofstream out("./b_large.out");
	int t;
	inp>>t;
	
	for(int a =1 ;a <=t; a++){
		ll ans = -1; 
		int n;
		inp>>n;
		vpll vec;
		ll lt = 0, rt = inf;
		for(int i=0; i<n; i++){
			ll p, k;
			inp>>p>>k;
			pll rng;
			if(p==100){
				rng = mp(k, k);
			}
			else rng = mp((100*k)/(p+1) +1 , (p==0)?inf:(100*k)/p );
			
			//out<<"current range "<<rng.F<<" "<<rng.S<<endl;
			
			lt = max(lt, rng.F);
			rt = min(rt, rng.S);
			//out<<"best range "<<lt<<" "<<rt<<endl;
		}	
		if(lt == rt){
			ans = lt;
		}
		
		/*
		ll low = 0;
		ll high = 2000;
		ll mid = -1;
		while(low<=high){
			mid = (low+high)/2;
			out<<"trying val "<<mid<<endl;
			int err = check_ans(mid, vec);
			if(err==1){
				low = mid+1;
			}
			else if (err == -1){
				high = mid - 1;
			}
			else{
				int left = check_ans(mid-1, vec);
				int right = check_ans(mid+1, vec);
				if(left == 0 && right == 0){
					ans = -1;
				}
				else{
					ans = mid;
				}
				break;
			}
		}
		*/
			
		
		out<<"Case #"<< a <<": "<< ans<<endl;
	}
}
