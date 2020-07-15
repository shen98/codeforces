#include <iostream>
#include <vector>
using namespace std;

const int N = 2e3 + 9;
int n, m, W, w[N], b[N], f[N], c[N], d[N], dp[N];
vector<int> v[N];

int find(int x) { return x == f[x] ? x : find(f[x]); }

int main() {
    cin >> n >> m >> W;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) f[i] =i;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        f[find(v)] = find(u);
    }

    for(int i = 1; i <= n; ++i) {
        c[find(i)] += w[i];
        d[find(i)] += b[i];
        v[find(i)].push_back(i);
    }

    for(int i = 1; i <= n; ++i) {
        if(f[i] == i) {
            for(int j = W; j >= 0; j--) {
                for(auto u : v[i]) {
                    if(j >= w[u]) 
                        dp[j] = max(dp[j], dp[j - w[u]] + b[u]);
                }
                if(j >= c[i])
                    dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
            }
        }
    }

    cout <<dp[W] << endl;
}
