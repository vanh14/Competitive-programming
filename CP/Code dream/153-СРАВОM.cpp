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

#define FOR(i, a, n) for(int i = (a) ; i <= (n) ; i++ )
#define FORD(i, a, n) for(int i = (a); i >= (n); i--)
#define FORX(i, x) for(auto (i) : (x))
#define ms(a, x) memset((a), (x), sizeof((a)))
#define all(a) (a).begin(), (a).end()
#define All(a, n) (a) + 1, (a) + 1 + n

const int INF = 1e18;
const int mod = 1e9+7;
const int N = 1e3 + 5;
int MOD = 998244353;
int bit[200000];
int n, m, k,stx, sty, ex, ey;
char a[N][N];
bool vis[N][N];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
int d[N][N];
void nhap(){
	cin >> n >> m;
	FOR(i, 1, n){
		FOR(j, 1, m){
			cin >> a[i][j];
			if(a[i][j] == 'G'){
				stx = i, sty = j;

			}
			else if(a[i][j] == 'R'){
				ex = i, ey = j;
			}
			d[i][j] = INF;

		}

	}

}
void bfs(int sx, int sy){
	deque<pi> q; d[sx][sy] = 0;
	q.push_front({sx, sy});
	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop_front();
		FOR(i, 0, 3){
			int u = x + moveX[i];
			int v = y + moveY[i];

			if(u < 1 || u > n || v < 1 || v > m){
				continue;
			}

			if(a[u][v] == '*'){
				if(d[u][v] > d[x][y] + 1){
					d[u][v] = d[x][y] + 1;
					q.pb({u, v});
				}
			}
			else if(a[u][v] != '*'){
				if(d[u][v] > d[x][y]){
					d[u][v] = d[x][y];
					q.push_front({u, v});
				}
			}
		}
	}
	cout << d[ex][ey];
}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	bfs(stx, sty);
	return 0;
}
