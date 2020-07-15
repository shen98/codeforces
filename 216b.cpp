#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int f[N], n, m, ans, v, u;
int root(int v) { return f[v] < 0 ? v : f[v] = root(f[v]); }

int main() {
    memset(f, -1, sizeof f);
    cin >> n >> m;

    while(m--) {
        cin >> v >> u;
        if((v=root(v)) == (u=root(u)) && (-f[v]%2)) ans++;
        else f[v] += f[u], f[u] = v;
        cout << "***" << v << " " << u << endl;
        for(int i = 1; i <= n; ++i) cout << f[i] << " ";
        cout << endl;
    }
    if((n - ans) % 2) ans++;
    cout << ans << endl;
}
