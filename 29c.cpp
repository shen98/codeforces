#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int n;
//ll hd[N], vs[N], cur[N], id = 0;
/*vector<ll> g;*/
//unordered_map<int, int> map;
//unordered_map<int, int> rev;
/*bool f = 0;*/
/*struct edge { ll to, nx; } e[N << 1];*/

//struct tmp { int real, b; } t[N];
//void addEdge(ll u, ll v) {
    //static int cnt = 0;
    //e[++cnt] = (edge) { v, hd[u] };
    //hd[u] = cnt;
//}

//void dfs(ll u) {
    //if(f) return;
    //cur[u] = 1;
    //g.push_back(u);
    //bool flag = 0;
    //for(ll i = hd[u]; i; i = e[i].nx) {
        //ll v = e[i].to;
        //if(!cur[v]) { dfs(v); flag = 1; }
    //}

    //if(!flag) {
//[>        cout << "***  ";<]
        ////for(auto a : g) cout << a << " ";
        //[>cout << endl;<]
        //if(g.size() == n + 1) { f = 1; return; }
        ////for(auto a : g) vs[a] = 1;
    //}

    //if(f) return;
    //g.pop_back();
//}

int main() {
    cin >> n;

    unordered_map<ll, vector<ll>> map;
    for(int i = 1; i <= n; ++i) {
        ll u, v;
        cin >> u >> v;
        map[u].push_back(v);
        unordered_map<ll, bool> vs;
        map[v].push_back(u);
    }

    ll root;
    for(auto a : map) {
        if(a.second.size() == 1) { root = a.first; break; }
    }

    unordered_map<ll, bool> vs;
    cout << root << " ";
    while(!vs[root]) {
        vs[root] = 1;
        for(auto v : map[root]) {
            if(!vs[v]) {
                root = v;
                cout << root << " ";
                break;
            }
        }
    }
    //for(int i = 1; i <= n; ++i) {
        //ll u, v;
        //cin >> u >> v;
        //if(map[u] != 0) u = map[u];
        //else { rev[++id] = u; map[u] = id; u = map[u]; }   

        //if(map[v] != 0) v = map[v];
        //else { rev[++id] = v; map[v] = id; v = map[v]; }
        ////cout << u << " " << v << endl ;
        //addEdge(u, v);
        //addEdge(v, u);
    //}

    ////cout << 1 << endl;
    //for(int i = 1; i <= n + 1; ++i) {
        ////memset(cur, 0, sizeof cur);
        //for(int j = 1; j <= n + 1; ++j) cur[j] = 0;
        //dfs(i);
        //if(f)  break;
//[>        if(!vs[i]) {<]
            ////dfs(i);
        //[>}<]
    //}

//[>    for(int i = 1; i <= n; ++i) cout << rev[i] << " ";<]
    //[>cout << endl;<]
    //for(auto a : g) cout << rev[a] << " ";
    /*cout << endl;*/
}
