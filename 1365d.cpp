#include <iostream>
#include <cstring>
using namespace std;

const int N = 55;
int n, m, cnt = 0;
char s[N][N];
bool vs[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    //cout << "***" << x << " " << y << endl;
    vs[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if(vs[nx][ny] || s[nx][ny] == '#') continue;
        vs[nx][ny] = 1;
        dfs(nx, ny);
    }
    
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == 'B') {
                    for(int k = 0; k < 4; ++k) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                        if(s[nx][ny] == '.') s[nx][ny] = '#';
                    }
                }
            }
        }
        
        //cout << "&&&&&&&  " << (s[n][m] == '#') << endl;
/*        for(int i = 1; i <= n; ++i) {*/
            //for(int j = 1; j <= m; ++j) cout << s[i][j];
            //cout << endl;
        /*}*/
        memset(vs, false, sizeof vs);
        //if(s[n][m] == '#') { cout << "No" << endl; continue; }
        if(s[n][m] != '#')dfs(n, m);

        bool ans = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1;j <= m; ++j) {
                if(s[i][j] == 'G') ans &= vs[i][j];
                if(s[i][j] == 'B') ans &= !vs[i][j];
            }
        }

        cout << (ans ? "Yes" : "No") << endl;
    }
}
