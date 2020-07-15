#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int N = 105, M = 1e5 + 5;
int n, r1, c1, r2, c2;
int a[N], d[N][M];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

/*void dfs(int x, int y) {*/
    //for(int i = 0; i < 4; ++i) {
        //int nx = x + dx[i], ny = y + dy[i];
        //if(nx < 1 || nx > n || ny < 0 || ny > a[nx]) continue;
        //ny = min(ny, a[nx]);
        //if(d[nx][ny] > d[x][y] + 1) {
            //d[nx][ny] = d[x][y] + 1;
            //dfs(nx, ny);
        //}
    //}
/*}*/

void bfs() {
    queue<pii> q;
    q.emplace(r1, c1);
    d[r1][c1] = 0;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 0) continue;
            ny = min(ny, a[nx]);
            if(d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                q.emplace(nx, ny);
            }
            if(nx == r2 && ny == c2) return;
        }       
    }
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    cin >> n;

    for(int i = 1;i <= n; ++i) {
        cin >> a[i];
        a[i]++;
    }
    cin >> r1 >> c1 >> r2 >> c2;

    memset(d, 0x3f, sizeof d);
    bfs();
    
/*    for(int i = 1; i <= n; ++i) {*/
        //for(int j = 1; j <= a[i] + 1; ++j) cout << d[i][j] << " ";
        //cout << endl;
    /*}*/

    cout << d[r2][c2] << endl;
}
