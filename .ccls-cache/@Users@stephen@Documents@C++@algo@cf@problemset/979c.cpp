#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 3e5 + 5;
int n, x, y;
int hd[N], Fa[N], sz[N];
bool vs[N], flag = false;
ll ans = 0;
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    Fa[u] = fa;
    //if(u == x) flag = true;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
/*        if(vs[v]) continue;*/
        /*if(v == y && flag) continue;*/
        //ans++;
        //dfs(v);
        if(v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    //if(u == x) flag = false;
}

int main() {
    cin >> n >> x >> y;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(1, 0);

    ans = 1ll * (n - 1) * n;
    bool flag = false;
    int X = x, Y = y;
    for(;x;x=Fa[x]) {
        if(Fa[x] == y) { ans -= 1ll * sz[X] * (n - sz[x]); flag = true; }
    }
    x = X, y = Y;
    for(; y; y = Fa[y]) {
        if(Fa[y] == x) { ans -= 1ll * sz[Y] * (n - sz[y]); flag = true; }
    }

    if(!flag) ans -= 1ll * sz[X] * sz[Y];
    cout << ans << endl;
/*    for(int i = 1; i <= n; ++i) cout << sz[i] << " ";*/
    /*cout << endl;*/
/*    for(int i = 1; i <= n; ++i) {*/
        //memset(vs, false, sizeof vs);
        //flag = false;
        //dfs(i);
    /*}*/

    //cout << ans << endl;
}
