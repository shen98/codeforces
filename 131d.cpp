#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

const int N = 3005;

int dfn[N], n, step = 1;
stack<int> s;
bool vs[N];
vector<pii> e[N];
vector<int> ring;
int d[N];
bool flag = false;

void dfs(int u) {
    if(flag) return;
    dfn[u]= step;
    s.push(u);
    for(int i = 0; i < e[u].size(); ++i) {
        if(flag) return;
        if(vs[e[u][i].second]) continue;
        vs[e[u][i].second] = 1;
        int v = e[u][i].first;
        if(dfn[v]) {
            int j;
            while(!s.empty()) {
                j = s.top(); s.pop();
                ring.push_back(j);
                if(j == v) break;
            }
            flag = true;
        } else dfs(v);
    }
    if(flag) return;
    s.pop();
}

int main() {
    memset(dfn, 0, sizeof dfn);
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(make_pair(v, i));
        e[v].push_back(make_pair(u, i));
    }

    memset(vs, false, sizeof vs);
    //int step = 1;
    dfs(1);

/*    for(int i = 1; i <= n; ++i) cout << dfn[i] << " ";*/
    /*cout << endl;*/
    queue<int> q;
    memset(d, 0x3F, sizeof d);
    for(int i = 0; i < ring.size(); ++i) {
        q.push(ring[i]);
        d[ring[i]] = 0;
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i].first;
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; ++i) cout << d[i] << " ";
    cout << endl;
    return 0;
}

/*int n;*/
//int hd[N], vt[N], d[N];
//bool vs[N];
//vector<int> cyc;
/*bool found = false;*/

/*struct edge { int to, nx; } e[N << 1];*/

//void addEdge(int u, int v) {
    //static int cnt = 0;
    //e[++cnt] = (edge) { v, hd[u] };
    //hd[u] = cnt;
    //vt[v] ++;
//}

//void dfs(int u, int s, int p) {
    //if(found) return;
    //cyc.push_back(u);
    ////cout << "***" << u << " " << s << " " << p << endl;
    //vt[u]-=2;
    //for(int i = hd[u]; i; i = e[i].nx) {
        //int v = e[i].to;
        //if(v == p) continue;
        //if(v == s && p != s) { found = true; return; }
        //if(vt[v] >= 2) {
            //dfs(v, s, u);
        //}
    //}

    //if(found) return;
    //cyc.pop_back();
//}

//queue<pii> q;
//void solve() {
    //for(auto a : cyc) { q.emplace(a, 0); vs[a] = 1; }
    
    //while(!q.empty()) {
        //int u = q.front().first, dist = q.front().second;
        //q.pop();
        //d[u] = dist;
        //for(int i = hd[u]; i; i = e[i].nx) {
            //int v = e[i].to;
            //if(!vs[v]) {
                //q.emplace(v, dist + 1);
                //vs[v] = 1;
            //}
        //}
    //}
//}

//int main() {
    //cin >> n;

    //for(int i = 1; i <= n; ++i) {
        //int u, v;
        //cin >> u >> v;
        //addEdge(u, v);
        //addEdge(v, u);
    //}

    //for(int i = 1; i <= n; ++i) {
        //if(vt[i] >= 2 && !found) {
            //dfs(i, i, 0);
        //}
    //}

    //solve();

    //for(int i = 1; i <= n; ++i) cout << d[i] << " ";
    //cout << endl;
//[>    for(auto a : cyc) cout << a << " ";<]
    //[>cout << endl;<]

    
/*}*/
