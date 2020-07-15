#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

const int N = 2e5 + 5;
int n, num = 1;
int hd[N], f[N], fa[N];
bool vs[N], l[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int p) {
    fa[u] = p;
    vs[u] = 1;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(vs[v]) continue;
        l[u] = false;
        dfs(v, u);
    }
}

int main() {
    memset(l, true, sizeof l);
    cin >> n;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }


    for(int i = 1; i <= n; ++i) cin >> f[i];

    dfs(1, -1);
    if(f[1] != 1) { cout << "No" << endl; return 0; }

    int cur = 1;
    for(int i = 2; i <= n; ++i) {
        if(fa[f[i]] != f[cur]) {
            cur++;
            while(l[f[cur]] && cur <= n) cur++;
            if(fa[f[i]] != f[cur]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
