#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;
int n, m;
int k[N], p[N], cur[N];
vector<int> g[N];
/*int a[N], hd[N], vs[N], ans[N];*/
//vector<vector<int>> g;
/*vector<int> cur;*/

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
/*struct edge { int to, nx; } e[N << 1];*/

//void addEdge(int u, int v) {
    //static int cnt = 0;
    //e[++cnt] = (edge) { v, hd[u] };
    //hd[u] = cnt;
//}

//void dfs(int u, int s) {
    //vs[u] = 1;
    //cur.push_back(u);

    //for(int i = hd[u]; i; i = e[i].nx) {
        //int v = e[i].to;
        //if(!vs[v]) {
            //dfs(v, s);
        //}
    //}

    //if(u == s) {
        //g.push_back(cur);
        //cur.clear();
    //}
/*}*/

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 1; i <= n; ++i) cin >> k[i];

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        
        p[find(u)] = find(v);
/*        addEdge(u, v);*/
        /*addEdge(v, u);*/
    }

    for(int i = 1; i <= n; ++i) g[find(i)].push_back(k[i]);

    for(int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
        cur[i] = g[i].size();
    }

    for(int i = 1; i <= n; ++i) {
        cout << g[find(i)][--cur[find(i)]] << " ";
    }
    cout << endl;
/*    for(int i = 1; i <= n; ++i) {*/
        //if(!vs[i]) dfs(i, i);
    //}

    //for(auto t : g) {
        //vector<int> tmp;
        //for(int e : t) tmp.push_back(a[e]);
        //sort(t.begin(), t.end());
        //sort(tmp.begin(), tmp.end());
        //for(int i = 0; i < t.size(); ++i) ans[t[i]] = tmp[tmp.size() - 1- i];
    //}

    //for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    /*cout << endl;*/
}
