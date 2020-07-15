#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n;
int sz[N], vs[N], hd[N], dp[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int d) {
    sz[u] = 1;
    dp[u] = d;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!sz[v]) {
            dfs(v, d + 1);
            sz[u] += sz[v];
        }
    }
}

int main() {
    cin >> n;

    for(int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        addEdge(u, i);
        addEdge(i, u);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; ++i) cout << 0.5 * (n - sz[i] + dp[i]) + 1 << " ";


/*    for(int i = 1; i <= n; ++i) cout << sz[i] << " ";*/
    /*cout << endl;*/
}
