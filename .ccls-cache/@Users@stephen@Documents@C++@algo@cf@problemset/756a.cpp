#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
int n, top = 0, num = 0, id = 0;
int low[N], stack[N], ins[N], dfn[N], p[N];

void dfs(int u) {
    dfn[u] = low[u] = ++id;
    ins[u] = 1;
    stack[top++]  = u;

    int v = p[u];
    if(!dfn[v]) {
        dfs(v);
        low[u] = min(low[u], low[v]);
    } else if(ins[v]) low[u] = min(low[u], dfn[v]);

    if(low[u] == dfn[u]) {
        do {
            ins[stack[--top]] = 0;
        } while(stack[top] != u);
        num++;
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> p[i];

    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if(a == 1) cnt++;
    }
    if(cnt % 2 == 0) ans++;

    for(int i = 1; i <= n; ++i) if(!dfn[i]) dfs(i);

    ans += num == 1 ? 0 : num;
    cout << ans << endl;
}
