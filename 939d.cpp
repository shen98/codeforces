#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n, ans = 0;
int hd[N];
string s1, s2;
bool vs[N];
vector<pii> vec;
struct edge { int to, nx; } e[N << 1];

void addEdge(int u, int v) {
    static int cnt = 0;
    e[++cnt] = (edge){ v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u) {
    vs[u] = 1;
    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        if(!vs[v]) { dfs(v); ans++; vec.push_back(make_pair(u, v)); }
    }
}

int main() {
    cin >> n >> s1 >> s2;

    for(int i = 0; i < n; ++i) {
        int u = s1[i] - 'a' + 1, v = s2[i] - 'a' + 1;
        //cout << u << " " << v << endl;
        if(u != v) {
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    for(int i = 1; i <= 26; ++i) {
        if(!vs[i]) dfs(i);
    }

    cout << ans << endl;
    for(auto a : vec) {
        cout << (char)(a.first + 'a' - 1) << " " << (char)(a.second + 'a' - 1) << endl;
    }
    return 0;
}
