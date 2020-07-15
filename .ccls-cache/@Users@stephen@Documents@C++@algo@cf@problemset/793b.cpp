#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1005;
int n, m, sx, sy, fx, fy;
int g[N][N], d[N][N], pref[N][N];
bool vs[N][N], flag = false;
char s[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

/*int main() {*/
    //cin >> n >> m;
    //for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);

    //int X1, Y1, Y2, X2;
    //bool ans = 0;
    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) {
            //int aa = 0;
            //if(s[i][j] == 'S') X1 = i, Y1 = j;
            //if(s[i][j] == 'T') X2 = i, Y2 = j;
            //if(s[i][j] == '*') aa = 1;
            //pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + aa;
        //}
    //}

    //for(int i = 1; i <= m; ++i) {
        
    //}
/*}*/

/*void dfs(int x, int y, int num, int state)  {*/
    //cout << "***" << x << " " << y << " " <<  num << " " << state << endl;
    //if(flag) return;
    //vs[x][y] = 1;

    //for(int i = 0; i < 4; ++i) {
        //if(flag) return;
        //int nx = x + dx[i], ny = y + dy[i];
        //if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        //if(vs[nx][ny] || !g[nx][ny]) continue;
        //if(nx == fx && ny == fy) { flag = true; return; }
        ////cout << nx << " " << ny << " " << g[nx][ny] << endl;
        //vs[nx][ny] = 1;
        //int nxN = num;
        //if(state == -1) { nxN = 0; }
        //else if(i != state) nxN++;
        //if(nxN > 2) continue;
        //dfs(nx, ny, nxN, i);
    //}
/*}*/

void bfs() {
    queue<vector<int>> q;
    q.push({sx, sy, 0, -1});
    d[sx][sy] = 1;

    while(!q.empty()) {
        int x = q.front()[0], y = q.front()[1], num = q.front()[2], state = q.front()[3];
        q.pop();

        //cout << "***" << x << " " << y << " " << num << " " << state << endl;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if(!g[nx][ny]) continue;
            //cout << nx << " " << ny << " " << g[nx][ny] << endl;
            int nxN = num;
            if(state == -1) { nxN = 0; }
            else if(i != state) nxN++;
            if(nxN > 2 || d[nx][ny] < nxN) continue;
            d[nx][ny] = nxN;
            if(nx == fx && ny == fy) { flag = true; return; }
            q.push({nx, ny, nxN, i});
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;

        for(int j = 0; j < m; ++j) {
            if(s[j] != '*') g[i][j + 1] = 1;

            if(s[j] == 'S') { sx = i; sy = j + 1; }
            if(s[j] == 'T') { fx = i; fy = j + 1; }
        }
    }

    memset(d, 0x3F, sizeof d);
    bfs();
    //dfs(sx, sy, 0, -1);

    cout << (flag ? "YES" : "NO") << endl;
}
