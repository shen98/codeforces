#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m, k;
int d[N], route[N];
vector<int> fow[N], rev[N];
//struct edge { int to, nx; } fow[N << 1], rev[N << 1];

/*void addEdge(int u, int v) {*/
    //static int cnt = 0;
    //fow[++cnt] = (edge) { v, fhd[u] };
    //fhd[u] = cnt;
    //rev[++cnt] = (edge) { u, rhd[v] };
    //rhd[v] = cnt;
/*}*/

void bfs() {
    queue<pii> q;
    q.emplace(route[k], 1);
    d[route[k]] = 1;
    while(!q.empty()) {
        int u = q.front().first, dist = q.front().second; q.pop();

        for(int v : rev[u]) {
            //int v = rev[i].to;
            if(dist + 1 < d[v]) {
                d[v] = dist + 1;
                q.emplace(v, dist + 1);
            }
        }
    }
}

/*void bfsa() {*/
    //queue<pii> q;
    //q.emplace(route[1], 0);

    //while(!q.empty()) {
        //int u = q.front().first, dist = q.front().second; q.pop();
        //bool flag = 0;
        //for(int i = fhd[u]; i; i = fow[i].nx) {
            //int v = fow[i].to;
            //if(d[v] == d[u] - 1) {
                //if(v == route[dist + 1]) flag = 1;
                //q.emplace(v, dist + 1);
            //}
        //}
        //Max += num[u]
        //if(flag) Min+=num[u]
    //}
/*}*/
int main() {
    memset(d, 0x3f3f3f3f, sizeof d);
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        //addEdge(u, v);
        fow[u].push_back(v);
        rev[v].push_back(u);
    }

    cin >> k;

    for(int i = 1; i <= k; ++i) cin >> route[i];

    bfs();

    int ans1 = 0, ans2 = 0;

/*    for(int i = 1; i <= n; ++i) cout << d[i] << " ";*/
    /*cout << endl;*/
    for(int i = 1; i < k; ++i) {
        ans1 += d[route[i]] < d[route[i + 1]] + 1;
        //cout << "***" << d[route[i]] << " " << d[route[i + 1]] << " "   << ans1 << endl;
        bool f = 0;
        //for(int j = fhd[route[i]]; j; j = fow[j].nx) {
        for(int v : fow[route[i]]) {
            //int v = fow[j].to;
            if(d[v] + 1 == d[route[i]] && v != route[i + 1]) f = 1;
        }
        ans2 += f;
    }

    cout << ans1 << " " << ans2 << endl; 

/*    for(int i = 1; i <= n; ++i) cout << d[i] << " ";*/
    //cout << endl;
    //for(int i = 1; i <= n; ++i) cout << num[i] << " ";
    /*cout << endl;*/
}
