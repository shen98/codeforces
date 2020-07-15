#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1005;
int n, m, num = 0, gn = 1;
int cnt[N][N], group[N][N];
vector<string> str(N);
bool vs[N][N];
vector<pii> cc;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int sx, int sy) {
    if(str[x][y] == '*') return;
    vs[x][y] = 1;
    num++;
    cc.push_back({x, y});
    for(int i = 0; i < 4; ++i) {
        int nx = dx[i] + x, ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(!vs[nx][ny] && str[nx][ny] == '.') {
            dfs(nx, ny, sx, sy);
        }
    }

    if(x == sx && y == sy) {
    //cout << "***" << x << " " << y << " " << num << endl;
        for(auto p : cc) {
            //cout << p.first << " " << p.second << endl;
            cnt[p.first + 1][p.second + 1] = num;
            group[p.first + 1][p.second + 1] = gn; 
        }
        gn++;
        cc.clear();
        num = 0;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> str[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vs[i][j]) dfs(i, j, i, j);
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(str[i - 1][j - 1] == '*') {
                int tmp = 1;
                set<int> gn;
                for(int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(cnt[nx][ny] && gn.find(group[nx][ny]) == gn.end()) {
                        tmp += cnt[nx][ny];
                        gn.insert(group[nx][ny]);
                    }
                }
                str[i - 1][j - 1] = tmp % 10 + '0';
            }
                //str[i - 1][j - 1] = (cnt[i - 1][j] + cnt[i][j - 1] + cnt[i + 1][j] + cnt[i][j + 1] + 1) % 10 + '0';
        }
    }

    for(int i = 0; i < n; ++i) cout << str[i] << endl;
/*    for(int i = 0; i <= n + 1; ++i) {*/
        //for(int j = 0; j <= m + 1; ++j) cout << group[i][j] << " ";
        //cout << endl;
    /*}*/
}
