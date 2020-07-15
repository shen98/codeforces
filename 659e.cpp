#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;

int to[N << 1], nx[N << 1], vt[N], hd[N], Cnt, ans;
queue<int> q;
bool visit[N];

void addEdge(int u, int v) {
    to[Cnt] = v;
    nx[Cnt] = hd[u];
    vt[v]++;
    hd[u] = Cnt++;
}

int main() {
    memset(hd, -1, sizeof hd);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int i = 1; i <= n; ++i) if(vt[i] == 1) q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        visit[u] = true;
        for(int i = hd[u]; i != -1; i = nx[i]) {
            int v = to[i];
            if(visit[v]) continue;
            vt[v]--;
            if(vt[v] == 1) q.push(v);
        }
    }

    for(int i = 1; i <= n; ++i) if(!vt[i]) ans++;

    cout << ans << endl;

    return 0;
}

