
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
  #define DEBUG(X) //cerr << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << X << endl
#else
  #define DEBUG(X) (void)0
#endif

int main(){
	ifstream inp("./d_small.in");
	ofstream out("./d_small.out");
	int t;
	inp>>t;
	for(int a =1 ;a <=t; a++){
		int n,k,c,X;
		inp>>n>>k>>c>>X;
		//cerr<<"print n,k,c,x"<<endl;
		//cerr<<n<<" "<<k<<" "<<c<<" "<<X<<endl;
		vector<int> v1, v2;
		for(int i=0; i<n; i++){
			int x;
			inp>>x;
			int val = (i+1)*x;
			v1.pb(val);
		}
		for(int i=0; i<n; i++){
			int x;
			inp>>x;
			int val = (i+1)*x;
			v2.pb(val);
		}
		vector<vector<int>> mat ;
		for(int i=0; i<n; i++){
			vector<int> vec ;
			for(int j=0; j<n; j++){
				int val = (v1[i] + v2[j] + c)%X;
				vec.pb(val);
			}
			mat.pb(vec);
		}
		vector<vector<int>> rowmx;
		for(int i=0; i<n; i++){
			vector<int> vec;
			for(int j=0; j<=(n-k); j++){
				int mx = -1;
				for(int l = 0; l<k; l++){
					mx = max(mx, mat[i][j+l]);
				}
				vec.pb(mx); 
			}
			rowmx.pb(vec);
		}
		for(int i=0; i<n ; i++){
			for(int j=0; j<n; j++){
				//cerr<<mat[i][j]<<" ";
			}
			//cerr<<endl;
		}
		//cerr<<"printing rowmx"<<endl;
		for(int i=0; i<n ; i++){
			for(int j=0; j<=(n-k); j++){
				//cerr<<rowmx[i][j]<<" ";
			}
			//cerr<<endl;
		}
		//vector<vector<ll>> submx;
		ll ans = 0;
		for(int i=0; i<=(n-k); i++){
			//vector<int> vec;
			for(int j=0; j<=(n-k); j++){
				int mx = -1;
				for(int l=0; l<k; l++){
					mx = max(mx, rowmx[i+l][j]);
				}
				ans += mx;
				//vec.pb(mx);
			}
			//submx.pb(vec);
		}

		out<<"Case #"<<a<<": "<<ans<<endl;
	}
}
