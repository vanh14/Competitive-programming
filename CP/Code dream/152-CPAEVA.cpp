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
int n, m, k;
vector<int> adj[N];
bool vis[N];
vector<int> sh;
int d[N];
int par[N];
void nhap(){
    cin >> n >> k;
    FOR(i, 1, k){
        int x; cin >> x;
        sh.pb(x);
    }
    cin >> m;
    FOR(i, 1, m){
        int x, y;
        cin >> x >> y;
        adj[y].pb(x);
        adj[x].pb(y);
    }
}
void bfs(){
    queue<int> q;
    FORX(k, sh){
        vis[k] = 1;
        q.push(k);
        d[k] = 0;
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        FORX(u, adj[v]){
            if(!vis[u]){
                d[u] = d[v] + 1;
                vis[u]= 1;
                q.push(u);
            }
        }
    }
}
void solve(){
    bfs();
    FOR(i, 1, n){
        cout << d[i] << " ";
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
