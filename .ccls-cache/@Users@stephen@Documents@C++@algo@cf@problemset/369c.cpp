#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 100005;

vector<int> map[N];
int n;
int white[N], d[N];

void dfs(int u, int p) {
    d[u] = white[u];
    for(auto v : map[u]) {
        if(v == p) continue;

        dfs(v, u);
        d[u] += d[v];
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n - 1; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        map[x].push_back(y);
        map[y].push_back(x);

        if(t == 2) {
            white[x] = 1;
            white[y] = 1;
        }
    }

    dfs(1, -1);

    vector<int> ans;


    for(int i = 1; i <= n; ++i) {
        if(white[i] && d[i] == 1) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
