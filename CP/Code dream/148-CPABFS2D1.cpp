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
#define FORX(i, x) for(int (i) : (x))
#define ms(a, x) memeset((a), (x), sizeof((a)))
#define all(a) (a).begin(), (a).end()
#define All(a, n) (a) + 1, (a) + 1 + n


const int INF = 1e18;
const int mod = 1e9+7;
const int N = 1e3  + 5;
int MOD = 998244353;
int bit[200000];
int n, m;
int sx[] = {0, 0, 1, -1};
int sY[] = {1, -1, 0, 0};
char a[N][N];
int st, sy, et, ey;
int d[N][N];
bool vis[N][N];
char dir[4] = {'R', 'L', 'D', 'U'};
char trace[N][N];

void nhap(){
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                st = i, sy = j;
            }
            else if(a[i][j] == 'B'){
                et = i, ey = j;
            }
        }
    }
}

void bfs(int Sx, int Sy){
    d[Sx][Sy] = 0;
    vis[Sx][Sy] = true;
    queue<pi> q;
    q.push({Sx, Sy});
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;

        q.pop();
        if(a[x][y] == 'B') break;

        FOR(i, 0, 3){
            int u = x + sx[i];
            int v = y + sY[i];

            if(u < 1 || u > n){
                continue;
            }
            if(v > m || v < 1) continue;
            if(a[u][v] == '#') continue;

            if(!vis[u][v]){
                d[u][v] = d[x][y] + 1;
                q.push({u, v});
                vis[u][v] = 1;
                trace[u][v] = dir[i];
            }

        }
    }
    if(!vis[et][ey]){
        cout << "NO" << nn;
        return;
    }
    else{
        cout << "YES" << nn;
        cout << d[et][ey] << nn;
    }

    string path = "";
    int x = et, y  = ey;

    while(x != st || y != sy){
        char c = trace[x][y];
        path += c;
        if(c == 'R') y--;
        else if(c == 'L') y++;
        else if(c == 'D') x--;
        else if(c == 'U') x++;
    }

    reverse(path.begin(), path.end());
    cout << path;

}
signed main() {
	//freopen("CSBN.INP", "r", stdin);
	//freopen("CSBN.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    nhap();
    bfs(st, sy);
	return 0;

}
