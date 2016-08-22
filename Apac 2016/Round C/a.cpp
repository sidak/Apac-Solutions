
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
typedef pair<int,string > pis;
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
bool cmp(pis a , pis b ){
	if(a.F==b.F){
		return a.S>b.S;
	}
	else return a.F<b.F;
}
int main(){
	ifstream inp("./A_SMALL.in");
	ofstream out("./A_SMALL.out");
	int t;
	inp>>t;
	for(int a =1 ;a <=t; a++){
		
		int p;
		inp>>p;
		vector<int> scores ;
		for(int i=0; i<p; i++){
			int x;
			inp>>x;
			scores.pb(x);
		}
		int n;
		inp>>n;
		int m;
		map<string, vector<int>> mp;
		vector< pair<int, string> > vec;
		for(int i=0; i<n; i++){
			int w;
			inp>>w;
			//out<<"input wt is "<<w<<endl;
			
			for(int j=0; j<p; j++){
				string ath;
				inp>>ath;
				//out<<"input ath is "<<ath<<endl;
				int score = scores[j]*w;
				if(mp.find(ath)==mp.end()){
					vector<int> v;
					v.pb(score);
					mp[ath]=v;
				}
				else{
					mp[ath].pb(score);
				}
			}
		}
		inp>>m;
		for(auto it=mp.begin(); it!=mp.end(); it++){
			string ath = (*it).F;
			sort(mp[ath].begin(), mp[ath].end());
			vector<int> sorted = mp[ath];
			int comp = min(n, m);
			int i = sorted.size()-1;
			int j = 0;
			int ans = 0;
			while(i>=0 && j<comp){
				ans += sorted[i];
				i--;
				j++;
			}
			vec.pb(mp(ans, ath));
		}
		
		sort(vec.rbegin(), vec.rend(), cmp);
		int rk = 1;
		out<<"Case #"<<a<<": "<<endl;
		out<<rk<<": "<<vec[0].S<<endl;
		for(int i=1; i<vec.size(); i++){
			if(vec[i].F!=vec[i-1].F){
				rk = (i+1);
			}
			out<<rk<<": ";
			out<<vec[i].S<<endl;
		}
	}
}
