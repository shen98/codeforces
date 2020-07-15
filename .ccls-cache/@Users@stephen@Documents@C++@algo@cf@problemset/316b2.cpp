#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 1005;
int n, x, num = 0, start;
int hd[N];
bool vs[N], can[N];
vector<int> vec;
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u, int s, int l) {
    vs[u] = 1;
    if(u == x) { start = l; return; }
    bool flag = false;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) {
            vs[v] = 1;
            flag = true;
            dfs(v, s, l + 1);
        }
    }

    if(!flag) {
    //cout << "***" << u << " " << s << " " << l << endl;
        vec.push_back(l);
    }
}

int main() {
    cin >> n >> x;

    for(int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        addEdge(v, i);
    }

    dfs(0, 0, 0);

    for(int i = 1; i <= n; ++i) can[i] = false;
    can[start] = 1;
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = n; j >= 1; --j) {
            if(can[j]) can[j + vec[i]] = 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(can[i]) cout << i << endl;
    }
    //set<int> s;
/*    vector<int> ans = { start };*/
    //for(auto a : vec) {
        ////cout << a << endl;
        //int sz = ans.size();
        //for(int i = 0; i < sz; ++i) {
    
        //}ans.push_back(ans[i] + a);
    //}

    //ans.push_back(0);
    //sort(ans.begin(), ans.end());

    //for(int i = 1; i < ans.size(); ++i) {
        //if(ans[i] != ans[i - 1]) cout << ans[i] << endl;
    /*}*/

}
