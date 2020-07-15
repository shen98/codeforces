#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
int hd[N], vt[N], s[N << 1], vs[N], u[N], v[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
    vt[v]++;
}

void dfs(int u, int d) {
    vs[u] = d;

    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(vs[v]) continue;
        dfs(v, d == 2 ? 1 : 2);
    }
}
int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        addEdge(u[i], v[i]);
        addEdge(v[i], u[i]);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i]) dfs(i, 1);
    }

    for(int i = 1; i <= m; ++i) {
        if(vs[u[i]] == vs[v[i]]) { cout << "NO" << endl; return 0; }
    }

    cout << "YES" << endl;

    for(int i = 1; i <= m; ++i) {
        cout << (vs[u[i]] == 1) ? "1" : "0";
    }
    cout << endl;

    return 0;
}
