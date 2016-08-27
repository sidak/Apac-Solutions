
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

string numToBinStr(int x){
	string ans ="";
	for(int i=0; i<8; i++){
		if(x & 1){
			ans+='1';
		}
		else ans += '0';
		x>>=1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string ipToBinary(int * addr){
	string ans ="";
	for(int i=0; i<4; i++){
		ans += numToBinStr(addr[i]);
	}
	return ans;
}
string getNumStr(string x){
	int num = 0;
	for(int i=0; i<sz(x); i++){
		num<<=1;
		num|= (x[i]-'0');
	}
	return NumberToString(num);
}
string getIpFromBin(string x){
	int pre = sz(x);
	string bin = "00000000000000000000000000000000";
	for(int i=0; i<pre; i++){
		bin[i]=x[i];
	}
	string ans = getNumStr(bin.substr(0,8))+"." + getNumStr(bin.substr(8,8))+"." + getNumStr(bin.substr(16,8))+"." + getNumStr(bin.substr(24,8))+"/" + NumberToString(pre);
	return ans;
}
int main(){
	FILE * sFile, *dFile;
	sFile = fopen("./c_large.in", "r+");
	dFile = fopen("./c_large.out", "w+");
	

	//ifstream inp("./c_small.in");
	//ofstream out("./c_small.out");
	
	//ifstream inp("./c_large.in");
	//ofstream out("./c_large.out");
	
	int t;
	fscanf(sFile, "%d", &t);
	for(int cas =1 ;cas <=t; cas++){
		int n;
		fscanf(sFile, "%d", &n);
		list<string> ips;
		for(int i=0; i<n; i++){	
			int addr[4], pre;
			fscanf(sFile, "%d.%d.%d.%d/%d", &addr[0], &addr[1], &addr[2], &addr[3], &pre);
			string binIp = ipToBinary(addr);
			string normIp= binIp.substr(0, pre);
			ips.push_back(normIp);
		}
		ips.sort();
		
		
		while(true){
			bool noErase = true;
			list<string>::iterator it1 = ips.begin(), it2=ips.begin();
			it2++;
			while(it2!=ips.end()){
				bool erase = false;
				int i=0;
				string a = *it1;
				string b = *it2;
				
				while(i<a.size() && i<b.size() && a[i]==b[i]) i++;
				
				if(i==a.size()){
					it2= ips.erase(it2);
					noErase = false;
					erase = true;
				}
				else if (i== a.size()-1 && a.size()==b.size()){
					it2=ips.erase(it2);
					noErase = false;
					erase = true;
					*it1 = a.substr(0, sz(a)-1);
					
				}
				
				if(!erase){
					// otherwise if erase in this iteration, then the increment has already happened in it
					it1++;
					it2++;
				}
			}
			
			if(noErase) break;
		}
		fprintf(dFile, "Case #%d:\n", cas);
		for(auto it = ips.begin(); it!=ips.end(); it++){
			string x = *it;
			string ans = getIpFromBin(x);
			fprintf(dFile, "%s\n", ans.c_str());
		}
	}
}
