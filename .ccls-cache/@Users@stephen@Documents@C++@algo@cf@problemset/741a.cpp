#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
const int N = 105;
int n, ans, hd[N], a[N];
/*bool vs[N];*/

//int main() {
    //cin >> n;
    //for(int i = 0; i < n; ++i) {
        //cin >> a[i];
        //--a[i];
    //}

    //ll ans = 1;
    //for(int i = 0; i < n; ++i) {
        //int cur = i, t = 0;
        //if(vs[cur]) continue;
        //while(!vs[cur]) {
            //++t;
            //vs[cur] = 1;
            //cur = a[cur];
        //}

        //if(cur != i) { cout << -1 << endl; return 0; }
        //if(t % 2 == 0) t /= 2;
        //ans = lcm(t, ans);
    //}
    //cout << ans << endl;

    //return 0;
/*}*/

vector<int> vec;
bool vs[N];

struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge) { v, hd[u] }; 
    hd[u] = cnt;
}

int dfs(int u, int s, int l) {
    //cout << "*** " << u << " " << s << " " << l << endl;
    vs[u] = 1;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        cout << "***" << u << " " << v << " " << i << endl;
        if(v == s) { vec.push_back(l); return 0; }
        //if(!vs[v]) {
        if(dfs(v, s, l + 1) == 0) return 0;
        //}
    }

    cout << u << " " << s << endl;
    if(u != s)vec.push_back(-1);
    else vec.push_back(1);
    return -1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        addEdge(i, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i]) dfs(i, i, 1);
    }

    int ans = 1;
    for(auto a : vec) {
        if(a == -1) { cout << -1 << endl; return 0; }
        if(a % 2 == 0) a /= 2;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
}
