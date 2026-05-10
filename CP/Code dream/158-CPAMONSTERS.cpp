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
const int N = 1e3  + 5;
int MOD = 998244353;
int bit[200000];
int n, m;
char a[N][N];
bool vis[N][N];
bool visited[N][N];
int d[N][N];
int dist[N][N];
int sx[] = {0, 0, 1, -1};
int sy[] = {1, -1, 0, 0};
int stx, sty;
queue<pi> q;
bool ok;
char trace[N][N];
void nhap(){
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> a[i][j];
            if(a[i][j] == 'M'){
                q.push({i, j});
                d[i][j] = 0;
                vis[i][j] = 1;
            }
            else if(a[i][j] == 'A'){
                stx = i, sty = j;
            }
        }
    }
}
void bfs1(){
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        FOR(i, 0, 3){
            int u = x + sx[i];
            int v = y + sy[i];


            if(u < 1 || u > n || v < 1 || v > m || a[u][v] == '#'){
                continue;
            }
            if(!vis[u][v]){
                d[u][v] = d[x][y] + 1;
                vis[u][v] = 1;
                q.push({u, v});
            }
        }
    }
}
void bfs2(int Sx, int Sy){
    q.push({Sx, Sy});
    visited[Sx][Sy] = 1;
    dist[Sx][Sy] = 0;
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        if(x == 1 || x == n || y == 1 || y == m){
            ok = true;
            cout << "YES" << nn;
            cout << dist[x][y] << nn;

            string path;
            int cx = x, cy = y;

            while(cx != stx || cy != sty) {
                char c = trace[cx][cy];
                path.push_back(c);

                if(c == 'R') cy--;
                else if(c == 'L') cy++;
                else if(c == 'D') cx--;
                else if(c == 'U') cx++;
            }

            reverse(path.begin(), path.end());
            cout << path << "\n";
            break;
        }
        FOR(i, 0, 3){
            int u = x + sx[i];
            int v = y + sy[i];


            if(u < 1 || u > n || v < 1 || v > m || a[u][v] == '#'){
                continue;
            }
            if(!visited[u][v] && ( dist[x][y] + 1 < d[u][v] || (d[u][v] == 0 && a[u][v] == '.' ))){
                dist[u][v] = dist[x][y] + 1;
                visited[u][v] = 1;
                q.push({u, v});
                if(i == 0) trace[u][v] = 'R';
                if(i == 1) trace[u][v] = 'L';
                if(i == 2) trace[u][v] = 'D';
                if(i == 3) trace[u][v] = 'U';
            }
        }
    }
    if(!ok){
        cout << "NO" << nn;
    }
}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	nhap();
	bfs1();
	bfs2(stx, sty);
    return 0;
}
