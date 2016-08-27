
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
typedef queue<pair<int,int>> qpii;

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
int arr[101][101];
int visited[101][101];
void bfs(qpii & q, int r, int c){
	
	while(!q.empty()){
		pii pt = q.front();
		int x = pt.F;
		int y = pt.S;
		q.pop();
		
		if(x>0 && visited[x-1][y]==0 && arr[x-1][y]==1){
			q.push(mp(x-1,y));
			visited[x-1][y]=1;
		}
		if(y>0 && visited[x][y-1]==0 && arr[x][y-1]==1){
			q.push(mp(x,y-1));
			visited[x][y-1]=1;
		}
		if(x<(r-1) && visited[x+1][y]==0 && arr[x+1][y]==1){
			q.push(mp(x+1,y));
			visited[x+1][y]=1;
		}
		if(y<(c-1) && visited[x][y+1]==0 && arr[x][y+1]==1){
			q.push(mp(x,y+1));
			visited[x][y+1]=1;
		}
		
	} 
}
int find_conn_comp(int r, int c){
	int ans = 0;
	memset(visited, 0, sizeof(visited));
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(visited[i][j]==0 && arr[i][j]==1){
				qpii q;
				q.push(mp(i,j));
				visited[i][j]=1;
				//cerr<<"going for bfs "<<i<<" "<<j<<endl;
				bfs(q,r,c);
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	ifstream inp("./a_large.in");
	ofstream out("./a_large.out");
	int t;
	inp>>t;
	
	for(int a =1 ;a <=t; a++){
		out<<"Case #"<<a<<": "<<endl;
		int r,c;
		inp>>r>>c;
		
		for(int i=0; i<r; i++){
			string w;
			inp>>w;
			for(int j=0; j<c; j++){
				arr[i][j]=w[j]-'0';
				//cerr<<arr[i][j]<<endl;
			}
		}
		int n;
		inp>>n;
		for(int i=0; i<n; i++){
			char q;
			inp>>q;
			if(q=='Q'){
				out<<find_conn_comp(r,c)<<endl;
			}
			else if(q=='M'){
				int x,y,z;
				inp>>x>>y>>z;
				arr[x][y]=z;
			}
		}
	}
}
