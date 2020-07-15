#include <iostream>

using namespace std;

const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int n, sum = 0, cur;
int w[N], hd[N], vs[N], used[N], nxt[N];

/*struct edge { int to, nx; } e[N << 1];*/

//void addEdge(int u, int v) {
    //static int cnt = 0;
    //e[++cnt] = (edge) { v, hd[u] };
    //hd[u] = cnt;
/*}*/

void newLoop(int u, int s, int m) {
    if(used[u] > 0) {
        if(used[u] == s) sum += m;
        return;
    }
    used[u] = s;
    newLoop(nxt[u], s, min(m, w[u]));
}

void dfs(int u) {
    cout << "***" << u << endl;
    for(int i = 1; i <= n; ++i) cout << used[i] << " "
    if(vs[u]) {
        if(!used[u]) newLoop(u, u, inf);
        return;
    }

    vs[u] = 1;
    dfs(nxt[u]);
    //cur = min(cur, w[u]);

    /*for(int i = hd[u]; i; i = e[i].nx) {*/
        //int v = e[i].to;
        //if(!vs[v]) {
            //dfs(v);
        //}
    /*}*/
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i) {
        cin >> nxt[i];
        //addEdge(i, u);
    }

    for(int i = 1; i <= n; ++i) dfs(i);
    cout << sum << endl;
  /*  for(int i = 1; i <= n; ++i) {*/
        //if(!vs[i]) {
            //cur = inf;
            //dfs(i);
            //sum += cur;
        //}
    //}

    /*cout << sum << endl;*/
}
