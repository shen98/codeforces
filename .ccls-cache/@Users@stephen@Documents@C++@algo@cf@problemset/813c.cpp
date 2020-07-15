#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, x;
int hd[N], d[N], l[N], pa[N];
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

/*void dfs(int u, int d) {*/
    //d1[u] = d;
    //for(int i = hd[u]; i; i = e[i].nx) {
        //int v = e[i].to;
        //if(!)
    //}
/*}*/

/*void bfs() {*/
    //queue<int> q;
    //q.push(1);
    //d1[1] = 1;

    //while(!q.empty()) {
        //int u = q.front();
        //q.pop();
        //for(int i = hd[u]; i; i = e[i].nx) {
            //int v = e[i].to;
            //if(!d1[v]) {
                //d1[v] = d1[u] + 1;
                //q.push(v);
            //}
        //}
    //}
/*}*/

void dfs(int u, int p) {
    pa[u] = p;
    l[u] = d[u] = d[p] + 1;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(v != p) {
            dfs(v, u);
            l[u] = max(l[u], l[v]);
        }
    }
}

int main() {
    cin >> n >> x;

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    d[0] = -1;
    dfs(1, 0);

    int ans = d[x];
    for(int u = x; d[x] - d[u] < d[u]; u = pa[u]) {
        ans = max(l[u] * 2, ans);
    }
    cout << ans << endl;
/*    for(int i = 1; i <= n; ++i) cout << l[i] << " ";*/
    /*cout << endl;*/
    //bfs();

/*    for(int i = 1; i <= n; ++i) cout << d1[i] << " ";*/
    /*cout << endl;*/
/*    queue<pii> q;*/
    //q.emplace(x, 1);
    //int ans = 0;
    //while(!q.empty()) {
        //int u = q.front().first, d = q.front().second;
        //q.pop();

        //ans = max(ans, d1[u]);
        //for(int i = hd[u]; i; i = e[i].nx) {
            //int v = e[i].to;
            //if(d < d1[v] - 1) {
                //q.emplace(v, d + 1);
                ////ans = max(ans, d1[v]);
            //}
        //}
    //}

//[>    for(int i = 1; i <= n; ++i) cout << d2[i] << " ";<]
    //[>cout << endl;<]
    /*cout << (ans - 1) * 2 << endl;*/
}
