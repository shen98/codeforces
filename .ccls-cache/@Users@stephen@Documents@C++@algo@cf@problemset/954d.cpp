#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int N = 1005;
int n, m, s, t, lvl = 0, num = 0;
vector<int> g[N];

vector<int> bfs(int s) {
    vector<bool> vs(n, false);
    vector<int> d(N);
    queue<pii> q;
    q.emplace(s, 0);
    vs[s] = 1;
    while(!q.empty()) {
        int u = q.front().first, l = q.front().second;
        q.pop();
        d[u] = l;
        for(auto v : g[u]) {
            if(!vs[v]) {
                q.emplace(v, l + 1);
                vs[v] = 1;
            }
        }
    }

    return d;
}

int main() {
    cin >> n >> m >> s >> t;

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto ds = bfs(s);
    auto dt = bfs(t);

/*    for(int i = 1; i <= n; ++i) cout << ds[i] << " ";*/
    //cout << endl;
    //for(int i = 1; i <= n; ++i) cout << dt[i] << " ";
    /*cout << endl;*/
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(min(ds[i] + dt[j] + 1, ds[j] + dt[i] + 1) >= ds[t]) cnt++;
        }
    }

    cout << cnt - m << endl;
}
