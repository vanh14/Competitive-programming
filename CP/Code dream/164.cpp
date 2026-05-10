#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nn '\n'
#define pi pair<int, int>
#define unmp unordered_map
#define uns unordered_set
#define TASK ""

const int INF = LLONG_MAX;
int mod = 1e9+7;
const int N = 1e3 + 5;
int MOD = 998244353;
int bit[200000];
int n, m, s, t;
int x[N];
vector<pi> adj[N];
vector d(N + 1, INF);
void nhap(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n ; i++){
        cin >> x[i];
    }
    for( int i = 1 ; i <= m; i++){
        int x, y , w;
        cin >> x >> y >> w;
        adj[x].eb(y, w);
        adj[y].eb( x, w );
    }
}
void dijkstra(int s){
    d[s] = 0;
    priority_queue<pi, vector<pi> , greater<pi>> q;
    q.push({0, s});
    while(!q.empty()){
        pi top = q.top(); q.pop();
        int  u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;

        for(auto [v, w] : adj[u]){
            if(d[u] + w >= x[v] && x[v] > 0){
                continue;
            }
            else if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }

    }
    if(d[t] == INF || (x[t] > 0 && d[t] >= x[t])){
        cout << -1;
    }
    else{
        cout << d[t];
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    nhap();
    dijkstra(s);
	return 0;
}
