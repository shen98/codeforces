#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, M = 3e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, id = 0, top = 0;
int c[N], hd[N], low[N], dfn[N], ins[N], stack[M];
bool vs[N], flag = 0;
ll ans = 1, sum = 0;
vector<vector<int>> group;
vector<int> cur;
struct edge { int to, nx; } e[M];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++id;
    ins[u] = 1;
    stack[top++] = u;

    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }

    if(low[u] == dfn[u]) {
        int Min = inf, cnt = 0, tmp;
        do {
            ins[tmp = stack[--top]] = 0;
            if(c[tmp] < Min) {
                Min = c[tmp];
                cnt = 1;
            } else if(c[tmp] == Min) cnt++;
        } while(stack[top] != u);
        sum += Min;
        ans = ans * cnt % mod;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) tarjan(i);
    }

    cout << sum << " " << ans << endl;
}
/*void dfs(int u, int s) {*/
    //vs[u] = 1;
    //cur.push_back(u);
    //for(int i = hd[u]; i; i = e[i].nx) {
        //int v = e[i].to;
        //if(v == s) flag = 1;
        //if(!vs[v]) dfs(v, s);
    //}

    //if(u == s && flag) {
        //group.push_back(cur);
        //cur.clear();
        //flag = 0;
    //}
//}

//int main() {
    //cin >> n;

    //for(int i = 1; i <= n; ++i) cin >> c[i];

    //cin >> m;

    //for(int i = 1; i <= m; ++i) {
        //int u, v;
        //cin >> u >> v;
        //addEdge(u, v);
    //}

    //for(int i = 1; i <= n; ++i) {
        //if(!vs[i]) dfs(i, i);
    //}

    //for(auto a : group) {
        //for(auto b : a) cout << b << " ";
        //cout << endl;
    //}
    ////vector<int> tmp;
    ////ll ans = 0, t = 1;
    ////for(auto a : group) {
        ////cout << "^^ ";
        ////int cnt = 0, curMin = INT_MAX;
        ////for(auto b : a) {
            ////cout << b << " ";
            ////if(c[b] < curMin) { curMin = c[b]; cnt = 1; }
            ////else if(c[b] == curMin) cnt++;
        ////}
        ////cout << endl;
        ////cout << "***" << curMin << " " << cnt << endl;
        ////tmp.push_back(cnt);
        ////ans = (ans + curMin) % mod;
    ////}


    ////for(auto a : tmp) t *= a;

    //[>cout << ans << " " << t << endl;<]
/*}*/
