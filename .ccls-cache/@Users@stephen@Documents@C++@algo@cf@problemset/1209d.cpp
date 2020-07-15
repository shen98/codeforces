#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n, k, fa[N], ans = 0;

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) fa[i] = i;
    while(k--) {
        int u, v;
        cin >> u >> v;
        int x = find(u), y = find(v);
        if(x == y) ans++;
        else fa[x] = find(fa[y]);
    }

    cout << ans << endl;
}
