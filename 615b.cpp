#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
long long n, m, ans = 0;
long long hd[N], vt[N], vs[N], dp[N];
vector<int> g[N];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[max(u,v)].push_back(min(u, v));
        vt[u]++;
        vt[v]++;
/*        addEdge(u, v);*/
        /*addEdge(v, u);*/
    }

/*    for(int i = 1; i <= n; ++i) cout << vt[i] << " ";*/
    /*cout << endl;*/
    for(int i = 1; i <= n; ++i) {
        for(auto u : g[i]) dp[i] = max(dp[i], dp[u] + 1);
    }

    for(int i = 1; i <= n; ++i) {
        ans = max(ans, vt[i] * (dp[i] + 1));
    }

    cout << ans << endl;
}
