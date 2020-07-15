#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int mod = 998244353;
const int N = 3e5 + 5;
int n, m, cnt = 0, ecnt, s1, s0;
int hd[N], vs[N], u[N], v[N];
bool flag;
vector<int> vec;

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    e[++ecnt] = (edge) { v, hd[u] };
    hd[u] = ecnt;
}
//int fa[N];

//int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void dfs(int u) {
    for(int i = hd[u]; i >= 0; i = e[i].nx) {
        int v = e[i].to;
        if(vs[v] == -1) {
            vs[v] = vs[u] ^ 1;
            if(vs[v] == 1) s1++;
            else s0++;
            dfs(v);
        } else if((vs[v] ^ vs[u]) == 0) {

        //cout << "***" << u << " " << v << endl;
            flag = 0;
        }
    }
}

int p(int x, int k) { 
    int ans = 1;
    while(k) {
        if(k & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod;
        k >>= 1;
    }

    //cout << "***" << x << " " << k << " " << ans << endl;
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        //for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 1; i <= n; ++i) hd[i] = vs[i] = -1;
        ecnt = 0;
        for(int i = 1; i <= m; ++i) {
            cin >> u[i] >> v[i];
            addEdge(u[i], v[i]);
            addEdge(v[i], u[i]);
        }

        flag = 1;
        int ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(vs[i] == -1) {
                s1 = 0; s0 = 1;
                vs[i] = 0;
                //cout << "***" << flag << " " << ans << endl;
                dfs(i);

                if(s1 == 0) ans = 1ll * ans * 3 % mod;
                else ans = 1ll * ans * (p(2, s0) + p(2, s1)) % mod;


            }
        }

        //cout << "^^^^^^^^" << ans << endl;
        if(!flag) cout << 0 << endl;
        else cout << ans << endl;

/*        bool ans = 1;*/
        //for(int i = 1; i <= m; ++i) {
            //if(vs[u[i]] % 2 == vs[v[i]] % 2) { ans = 0; break; }
        //}

        //ll sum = 0;
        //if(!ans) cout << 0 << endl;
        //else {
            //for(auto num : vec) {
                //sum += pow(2, num / 2) + pow(2, (num + 1) / 2);
                //sum %= mod;
            //}

            //cout << sum << endl;
        /*}*/
    }
}
