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
#define FORD(i, a, n) for(int i = (a); i >= (n); i--)
#define FORX(i, x) for(auto (i) : (x))
#define ms(a, x) memset((a), (x), sizeof((a)))
#define all(a) (a).begin(), (a).end()
#define All(a, n) (a) + 1, (a) + 1 + n


const int INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5  + 5;
int MOD = 998244353;
int bit[200000];
int n, m;
vector<pi> adj[N];
void nhap(){
    cin >> n >> m;
    FOR(i, 1 ,m){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].eb(y, w);
    }
}
void dijkstra(int s){
    vector<int> d(N, INF), parent(N, -1);
    d[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({d[s], s});
    while(!pq.empty()){
        pi top = pq.top(); pq.pop();
        int u = top.se;
        int kc = top.fi;
        if(kc > d[u]) continue;
        for(auto [v, w] : adj[u]){
            if(d[v] > d[u] + w){
                parent[v] = u; 
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    FOR(i, 1, n){
        cout << d[i] << " ";
    }
    // vector<int> path;
    // int cur = n;
    // while(cur != -1){
    //     path.pb(cur);
    //     cur = parent[cur];
    // }
    // reverse(all(path));
    // for(int x : path) cout << x << " ";
}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    nhap();
    dijkstra(1);
    return 0;
}
