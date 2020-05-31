#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

vector<vector<int>> map(N);
vector<int> a(N), b(N), c(N);


int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }


}

