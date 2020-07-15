#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int n;
int hd[N], sz[N];
bool vs[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

int dfs(int u) {
    vs[u] = 1;
    int cnt = 1;
    bool flag = false;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) {
            cnt += dfs(v);
            vs[v] = 1;
            flag = true;
        }
    }

    if(flag) cnt--;
    sz[u] = cnt;
    return cnt;
}

int main() {
    cin >> n;

    for(int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        addEdge(i, u);
        addEdge(u, i);
    }

    dfs(1);

    sort(sz + 1, sz + 1 + n);
    for(int i = 1; i <= n; ++i) {
        cout << sz[i] << " ";
    }

    cout << endl;
/*    for(int i = 1; i <= n; ++i) cout << sz[i] << " ";*/
    /*cout << endl;*/

}
