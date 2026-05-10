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
const int N = 1e5 + 5;
int MOD = 998244353;
int bit[200000];
int n, m, k, s, t;
int x[N];
vector<pi> adj[N];
vector d(N + 1, vector<int>(19, INF));
void nhap(){
    cin >> n >> m >> k;
    for( int i = 1 ; i <= m; i++){
        int x, y , w;
        cin >> x >> y >> w;
        adj[x].eb(y, w);
        adj[y].eb( x, w );
    }
}
void dijkstra(int s){
    d[s][k] = 0;
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    q.push({d[s][k], s, k});
    while(!q.empty()){
        auto [kc, u, ud] = q.top(); q.pop();
        if(kc > d[u][ud]) continue;

        for(auto [v, w] : adj[u]){
            if(d[v][ud] > kc + w){
                d[v][ud] = kc + w;
                q.push({d[v][ud], v, ud});
            }
            if(ud > 0){
                if(d[v][ud - 1] > kc + 0){
                    d[v][ud - 1] = kc ;
                    q.push({d[v][ud - 1], v, ud - 1});
                }
            }
        }

    }
    for(int j = 1; j <= n; j++){
        int kq = INF;
        for(int i = 0; i <= k; i++){
            kq = min(kq, d[j][i]);
        }
        cout << kq << " ";
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
    dijkstra(1);
	return 0;
}
