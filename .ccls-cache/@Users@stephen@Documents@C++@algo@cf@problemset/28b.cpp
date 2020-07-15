#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 105;

int n;
int hd[N], f[N];
bool vs[N];
vector<vector<int>> group;
vector<int> cur;
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int s) {
    vs[u] = 1;
    cur.push_back(u);
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) {
            vs[v] = 1;
            dfs(v, s);
        }
    }

    if(u == s) {
        group.push_back(cur);
        cur.clear();
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> f[i];

    for(int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        if(i - v >= 1) { addEdge(i - v, i); addEdge(i, i - v); }
        if(i + v <= n) { addEdge(i + v, i); addEdge(i, i + v); }
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i]) dfs(i, i);
    }
  
    for(auto a : group) {
        vector<int> tmp;
        for(auto b : a) {
            tmp.push_back(f[b]);
        }

        sort(a.begin(), a.end());
        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != tmp[i]) { cout << "NO" << endl; return 0; }
        }
    }

    cout << "YES" << endl;
}
