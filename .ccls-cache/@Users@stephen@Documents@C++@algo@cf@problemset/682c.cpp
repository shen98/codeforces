#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n, a[N], ans, hd[N];
bool vis[N];

struct edge { int to, next, w; } e[N << 1];

void addEdge(int u, int v, int w) {
    static int cnt = 0;
    e[++cnt] = (edge) {v, hd[u], w};
    hd[u] = cnt;
}

void dfs(int x, ll val) {
    vis[x] = true;
    ans++;
    for(int i = hd[x]; i; i = e[i].next) {
        int v = e[i].to;
        ll tmp = max(val + (ll)e[i].w, (ll)e[i].w);
        if((!vis[v]) && tmp <= a[v]) dfs(v, tmp);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i < n; ++i) {
        int u, w;
        cin >> u >> w;
        addEdge(i + 1, u, w);
        addEdge(u, i + 1, w);
    }

    dfs(1, 0);
    cout << n - ans << endl;

    return 0;
}
