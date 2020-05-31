#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
struct edge { int to, nt; } E[N << 1];
int H[N], edgeCnt, ans;
int n, col[N], fa[N];
void addEdge(int u, int v) { E[++ edgeCnt] = (edge) {v, H[u]}; H[u] = edgeCnt; }
/*void dfs(int u, int Fa) {*/
    //fa[u] = Fa; int cnt = 0;
    //for (int e = H[u]; e; e = E[e].nt) {
        //int v = E[e].to; if (v == fa[u]) continue;
        //++ cnt; 
        //while (cnt == col[u] || cnt == col[fa[u]]) ++ cnt;
        //col[v] = cnt; 
        //ans = max(ans, cnt);
        //dfs(v, u);
    //}
/*}*/

vector<vector<int>> map(N);

void dfs(int u, int p) {
    fa[u] = p; 
    int cnt = 0;

    for(auto v : map[u]) {
        if(v == fa[u]) continue;
        ++cnt;
        while(cnt == col[u] || cnt == col[fa[u]]) ++cnt;
        col[v] = cnt;
        ans = max(ans, cnt);
        dfs(v, u);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        //addEdge(x, y);
        //addEdge(y, x);
        map[x].push_back(y);
        map[y].push_back(x);
        //cout << "***" << H[x] << " " << H[y] << endl;
    }

    col[1] = 1;
    dfs(1, 0);

    cout << ans << endl;
    for(int i = 1; i <= n; ++i) cout << col[i]  << " ";
    cout << endl;

    return 0;
}
