#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
int hd[N];
bool vs[N], bit[N];
vector<int> v[2];
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int d) {
    vs[u] = 1;
    if(d == 1) v[0].push_back(u);
    else v[1].push_back(u);
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) {
            dfs(v, d == 2 ? 1 : 2);
        }
    }
}

/*void bfs() {*/
    //queue<pii> q;
    //q.emplace(1, 1);
    //vs[1] = 1;
    //while(!q.empty()) {
        //int u = q.front().first, d = q.front().second;
        //q.pop();
        //if(d == 1) v[0].push_back(u);
        //else v[1].push_back(u);
        //for(int i = hd[u]; i; i = e[i].nx) {
            //int v = e[i].to;
            //if(!vs[v]) {
                //vs[v] = 1;
                //q.emplace(v, d == 2 ? 1 : 2);
            //}
        //}
    //}
/*}*/
int main() {
    int t;
    cin >> t;

    while(t--) {
/*        memset(vs, false, sizeof vs);*/
        //memset(hd, 0, sizeof hd);
        /*memset(e, {}, sizeof e);*/
        v[0].clear();
        v[1].clear();
        for(int i = 1; i <= n; ++i) vs[i] = hd[i] = 0;
        for(int i = 1; i <= m; ++i) e[i] = {};
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }

        dfs(1, 1);
        
        if(v[0].size() <= n / 2) {
            cout << v[0].size() << endl;
            for(auto a : v[0]) cout << a << " ";
            cout << endl;
        } else {
            cout << v[1].size() << endl;
            for(auto a : v[1]) cout << a << " ";
            cout << endl;
        }
    }
}
