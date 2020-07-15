#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int n, m, id = 0, mx, ans = 0;
int hd[N], vs[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u) {
    mx = max(mx, u);
    vs[u] = 1;

    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) dfs(v);
    }

}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i]) {
            if(i < mx) ans++;
            dfs(i);
        }
    }

    cout << ans << endl;
/*    for(int i = 1; i <= n; ++i) cout << vs[i] << " ";*/
    /*cout << endl;*/
}
