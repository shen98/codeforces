#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
const int K = 1e5 + 5;
int n, m, k, cnt = 0, id = 0;
int dfn[N][N], vs[N][N];
char s[N][N];
vector<pii> start(K), cur;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int w[1000001], r[1000001];
/*int root(int u) {*/
    //if(r[u] < 0) return u;
    //return r[u] = root(r[u]);
//}

//void uni(int u, int v) {
    //u = root(u);
    //v = root(v);
    //if(u == v) return;
    //if(r[u] > r[v]) swap(u, v);
    //r[u] += r[v];
    //r[v] = u;
    //w[u] += w[v];
//}

//int main() {
    //cin >> n >> m >> k;

/*}*/
void dfs(int x, int y, int sx, int sy) {
    vs[x][y] = 1;
    //cout << "***" << x << " " << y << endl;
    cur.push_back({x, y});

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
/*        if(vs[nx][ny]) continue;*/
        //if(s[nx][ny] == '*') cnt++;
        /*else dfs(nx, ny);*/
        if(s[nx][ny] == '*') {
            //cout << nx << " " << ny << endl;
            if(vs[nx][ny] != -1) { cnt++; vs[nx][ny] = 1; }
        } else {
            if(!vs[nx][ny]) {
                vs[nx][ny] = 1;
                dfs(nx, ny, sx, sy);
            }
        }
    }

    if(x == sx && y == sy) {
        for(auto p : cur) {
            dfn[p.first][p.second] = cnt;
        }
        cnt = 0;
        cur.clear();
    }
}

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '.' && !vs[i][j]) {
                cnt = 0;
                //id++;
                dfs(i, j, i, j);
                //r[id] = cnt;
            }
        }
    }
    for(int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        cout << dfn[x][y] << endl;
       /* if(!dfn[x][y]) {*/
            //cout << "12312312312312" << endl;
            //memset(vs, false, sizeof vs);
            //dfs(x, y, x, y);
        //}

        //cout << dfn[x][y] << endl;
        //cout << endl;

        //for(int i = 1; i <= n; ++i) {
            //for(int j = 1; j <= m; ++j) cout << dfn[i][j] << " ";
            //cout << endl;
        /*}*/
    }

    return 0;
}
