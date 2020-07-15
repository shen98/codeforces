#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 55;
int n, m, k;
bool vis[N][N];
string matrix[55];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> p[10000];
int cnt = 0;

void wtfdfs(int x, int y) {
	vis[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && matrix[nx][ny] == '.') {
			wtfdfs(nx, ny);
		}
	}
}
 

void dfs(int x, int y) {
	vis[x][y] = true;
	p[cnt].push_back(make_pair(x, y));
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && matrix[nx][ny] == '.') {
			dfs(nx, ny);
		}
	}
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i) cin >> matrix[i];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if(!vis[i][j] && matrix[i][j] == '.') wtfdfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vis[i][j] && matrix[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }

    sort(p, p + cnt, [](vector<pair<int, int>>& v1, vector<pair<int, int>>& v2) {
                return v1.size() < v2.size();
            });

 /*   for(int i = 0; i < cnt; ++i) cout << p[i].size() << " ";*/
    /*cout << endl;*/
    int res = 0;
    for(int i = 0; i < cnt - k; ++i) {
        for(auto a : p[i]) matrix[a.first][a.second] = '*', res++;
    }

    cout << res << endl;
    for(int i = 0; i < n; ++i) cout << matrix[i] << endl;

    return 0;
}
/*bool visited[N][N];*/

//int dfs(int u, int v) {
    ////cout << "*** " << u << " " << v << endl;
    //if(!map[u][v]) return 0;
    //else if(u == 1 || u == n || v == 1 || v == m) return -1;
    //int cnt = map[u][v];
    //visited[u][v] = true;

    //for(int x = -1; x <= 1; ++x) {
        //for(int y = -1; y <= 1; ++y) {
            //if(x * x + y * y == 1) {
                //int i = u + x, j = v + y;
                //if(visited[i][j]) continue;
                    ////cout << "***" << u << " " << v << " " << " " << i << " " << j << " " << endl;
                //int t = dfs(i, j);
                //if(t == -1) { return -1; }
                //cnt += t;
            //}
        //}
    //}

    //return cnt;
//}

//void convert(int u, int v) {
    //if(!map[u][v]) return;
    //map[u][v] = 0;

    //for(int x = -1; x <= 1; ++x) {
        //for(int y = -1; y <= 1; ++y) {
            //if(x * x + y * y == 1) {
                //int i = u + x, j = v + y;
                //if(i == 0 || i == n + 1 || j == 0 || j == m + 1) return;
                //else { 
                    //convert(i, j);
                //}
            //}
        //}
    //}
//}

//int main() {
    //cin >> n >> m >> k;
    //for(int i = 0; i < n; ++i) {
        //string s;
        //cin >> s;
        //for(int j = 0; j < m; ++j) {
            //map[i + 1][j + 1] = (s[j] == '.');
        //}
    //}

    //int cnt = 0;
    //vector<pair<int, int>> v;
    //vector<vector<int>> p;
    ////cout << dfs(2, 2) << endl;;
    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) {
            //if(!visited[i][j]) {
                //int num = dfs(i, j);
                ////cout << "***" << i << " " << j << " " << num << endl;
                //if(num > 0) { 
                    //v.emplace_back(num, cnt++); 
                    //p.push_back({i, j});
                //}
            //}
        //}
    //}
    //sort(v.begin(), v.end());
//[>    for(auto a : v) cout << a.first << " ";<]
    //[>cout << endl;<]
    //int ans = 0;
    //for(int i = 0; i < v.size() - k; ++i) {
        //ans += v[i].first;
        //convert(p[v[i].second][0], p[v[i].second][1]);
    //}

    //cout << ans << endl;

    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) cout << (map[i][j] ? "." : "*");
        //cout << endl;
    //}
    //return 0;
/*}*/
