#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 105;
int t, n, k;
char g[4][N];
bool vs[4][N], flag = 0;

int dx[] = {1, 0, -1};

void dfs(int x, int y) {
    vs[x][y] = 1;

    //cout << "***"  << x << " " << y << endl;
    if(y >= n) { flag = 1; return; }
    if(g[x][y + 1] != '.') return;
    //y += 1;
    //y++;
    for(int i = 0; i < 3; ++i)  {
        int nx = x + dx[i], ny = y + 1;
        if(nx < 1 || nx > 3 || ny > n + 1) continue;
        if(g[nx][ny + 1] == '.' && g[nx][ny] == '.' && !vs[nx][ny + 2] && g[nx][ny + 3] == '.') dfs(nx, ny + 2);
    }
}

int main() {
    cin >> t;

    while(t--) {
        cin >> n >> k;
        memset(vs, 0, sizeof vs);
        for(int i = 1; i <= 3; ++i) cin >> (g[i] + 1);
    
        for(int i = 1; i <= 3; ++i) {
            for(int j = n + 1; j <= n + 5; ++j) g[i][j] = '.';
        }
        flag = 0;
        for(int i = 1; i <= 3; ++i) if(g[i][1] == 's') dfs(i, 1);

        cout << (flag ? "YES" : "NO") << endl;
    }
}
