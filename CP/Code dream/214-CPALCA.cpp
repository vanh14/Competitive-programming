#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define nn '\n'
#define pi pair<int, int>
#define unmp unordered_map
#define uns unordered_set
#define lb lower_bound
#define ub upper_bound
#define TASK " "


#define ms(a, x) memset((a), (x), sizeof((a)))
#define all(a) (a).begin(), (a).end()
#define All(a, n) (a) + 1, (a) + 1 + n

#define LOG 19
 
 
const int INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5 + 5;
int n, q;
vector<int> adj[N];
int par[N][LOG + 1];
int high[N];
void nhap(){
    cin >> n;
    for(int i = 1; i < n; i++){
    	int x, y;
    	cin >> x>> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
}
void dfs(int u, int p){
	par[u][0] = p;
	for(int i = 1; i <= LOG; i++){
		par[u][i] = par[par[u][i - 1]][i  - 1];
	}
	for(int v : adj[u]){
		if(v != p){
			high[v] = high[u] + 1;
			dfs(v, u);
		}
	}
}
int lca(int u, int v){
	// luon gia su high[u] > high[v]
	if(high[u] < high[v]) return lca(v, u);
	// can bang do sau
	for(int i = LOG; i >= 0; i--){
		if(high[par[u][i]] >= high[v]){
			u = par[u][i];
		}
	}
	if(u == v) return u;
	// cung nhau nhay len de tim  lca
	for(int i = LOG; i >= 0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void solve(){
	high[0] = -1;
	dfs(1, 0);
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << nn;
	}
}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	nhap();
	solve();
    return 0;
}
