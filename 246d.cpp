#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100005;

int col[N];
vector<set<int>> c(N);


int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0, pos = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        cin >> col[i];
        pos = min(pos, col[i]);
    }

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if(col[u] != col[v]) {
            c[col[u]].insert(col[v]);
            c[col[v]].insert(col[u]);
        }
    }

    for (int i = 0; i < c.size(); ++i) {
        if(c[i].size() > ans) {
            pos = i;
            ans = c[i].size();
        }
    }

    cout << pos << endl;
    return 0;
}
