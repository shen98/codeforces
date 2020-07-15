#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
int n, ans[N];
vector<int> fow[N], rev[N];

int dfs(int u, int p, int c = 0) {
    //cout << "***" << u << " " << p << " " << c << endl;
    ans[u] = c;
    int res = 0;
    for(auto v : fow[u]) {
        if(v != p) res += dfs(v, u, c + 1);
    }

    for(auto v : rev[u]) {
        if(v != p) res += dfs(v, u, c - 1) + 1;
    }
    return res;
}

int main() {
    cin >> n;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        fow[u].push_back(v);
        rev[v].push_back(u);
    }

    int t = dfs(1, 1), m = n;
    for(int i = 1; i <= n; ++i) m = min(m, ans[i]);
    cout << t + m << endl;
    for(int i = 1; i <= n; ++i) {
        if(ans[i] == m) cout << i << " ";
    }
    cout << endl;
/*    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";*/
    /*cout << endl;*/
}
