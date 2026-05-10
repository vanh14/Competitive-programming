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
#define pq priority_queue
#define TASK " "
#define FOR(i, a, n) for(int  i =  (a) ; i <= (n) ; i++ )


const int INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5  + 5;
int MOD = 998244353;
int bit[200000];
int n, m;
vector<int> adj[N];
bool vis[N];
vector<int> d(N, INF);
int par[N];

void inp(){
    cin >> n >> m;
    FOR(i, 1, m){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}

void bfs(int s){
    d[s] = 0;
    par[s] = -1;
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                d[v] = d[u] + 1;
                vis[v] = 1;
                q.push(v);
                par[v] = u;
            }
        }
    }
    if(d[n] == INF) cout << "IMPOSSIBLE" << nn;
    else cout << d[n] + 1 << nn;

    vector <int> path;
    for (int v = n; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    for (auto v : path) cout << v << ' ';

}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	inp();
    bfs(1);
	return 0;

}
