#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, ans, num = 0, mx = 0;
int c[N], hd[N], cc[N], g[N];

bool vs[N];
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int s) {
    vs[u] = 1;
    cc[c[u]]++;
    g[++g[0]] = c[u];
    mx = max(mx, cc[c[u]]);
    num++;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(vs[v]) continue;
        dfs(v, s);
    }
    if(u == s) {
        ans += num - mx;
    }
}

int main() {
    cin >> n >> m >> k;    
    for(int i = 1; i <= n; ++i) cin >> c[i];

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i]) {
            g[0] = 0;
            num = 0;
            mx = 0;
            dfs(i, i);
            for(int j = 1; j <= g[0]; ++j) cc[g[j]]--;
        }
    }

    cout << ans << endl;

    return 0;
}
