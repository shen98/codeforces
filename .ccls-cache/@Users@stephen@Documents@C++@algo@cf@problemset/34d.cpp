#include <iostream>

using namespace std;

const int N = 5e4 + 5;
int n, r1, r2;
int fa[N], hd[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u) {
    //cout << "***" << u << " " << fa[u] << endl;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!fa[v]) {
            fa[v] = u;
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> r1 >> r2;

    for(int i = 1; i <= n; ++i) {
        if(i == r1) continue;
        int v;
        cin >> v;
        addEdge(i, v);
        addEdge(v, i);
    }

    dfs(r2);

    for(int i = 1; i <= n; ++i) {
        if(i != r2) cout << fa[i] << " ";
    }

    cout << endl;

}
