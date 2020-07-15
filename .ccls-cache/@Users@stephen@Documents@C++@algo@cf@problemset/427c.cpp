#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, id = 0, top = 0;
int w[N], hd[N];
int dfn[N], low[N], ins[N], stack[M];
ll sum = 0, ans = 1;

struct edge { int to, nx; } e[M];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++id;
    ins[u] = 1;
    stack[top++] = u;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }

    if(dfn[u] == low[u]) {
        int Min = inf, cnt = 0, tmp;
        do{
            ins[tmp = stack[--top]] = 0;
            if(w[tmp] < Min) {
                Min = w[tmp];
                cnt = 1;
            } else if(w[tmp] == Min) cnt++;
        } while(stack[top] != u);
        sum += Min;
        ans = ans * cnt % mod;
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> w[i];

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) tarjan(i);
    }

    cout << sum << " " << ans << endl;
}
