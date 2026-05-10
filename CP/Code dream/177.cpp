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
int n, m;
int x[N];
vector<pi> adj[N];
vector d(N + 1, vector<int>(2, INF));
void nhap(){
    cin >> n >> m;
    for( int i = 1 ; i <= m; i++){
        int x, y , w;
        cin >> x >> y >> w;
        adj[x].eb(y, w);
        adj[y].eb( x, w );
    }
}
void dijkstra(int s){
    d[s][0] = 0;
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    q.push({d[s][0], s, 0});
    while(!q.empty()){
        auto [kc, u, ud] = q.top(); q.pop();
        if(kc > d[u][ud]) continue;

        for(auto [v, w] : adj[u]){
            if(d[v][ud] > kc + w){
                d[v][ud] = kc + w;
                q.push({d[v][ud], v, ud});
            }
            if(!ud){
                if(d[v][1] > kc + w / 2){
                    d[v][1] = kc + w / 2;
                    q.push({d[v][1], v, 1});
                }
            }
        }

    }
    cout << min(d[n][0], d[n][1]);
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
