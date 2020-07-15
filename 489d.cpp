#include <iostream>
#include <cstring>
using namespace std;

const int N = 3e4 + 5;
int n, m;
int hd[N], r[N];
bool vs[N];
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int l) {
    vs[u] = 1;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(l == 1) { 
            //cout << "***" << u << endl;
            r[v]++;
        }
        if(!vs[v] && l < 1) {
            dfs(v, l + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        dfs(i, 0);
/*        for(int j = 1; j <= n; ++j) cout << r[j] << " ";*/
        /*cout << endl;*/
        for(int j = 1; j <= n; ++j) {
            if(j == i) continue;
            if(r[j] >= 2) ans += (r[j] - 1) * r[j] / 2;
        }
        memset(r, 0, sizeof r);
        memset(vs, false, sizeof vs);
    }

    cout << ans << endl;
}
