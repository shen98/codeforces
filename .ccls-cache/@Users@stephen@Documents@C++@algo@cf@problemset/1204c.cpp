#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n, m, cur = 0;
int dis[105][105], p[N], l[105];
char s[105];
vector<int> E[105], ans;
int h, t, Q[105];
void bfs(int s, int *dis) {
    for(int i = 1; i <= n; ++i) dis[i] = INF;
    h = 0, t = 1, Q[t] = s, dis[s] = 0;
    while(h < t) {
        int u = Q[++h];
        for(int v : E[u]) if(dis[v] == INF) dis[v] = dis[u] + 1, Q[++t] = v;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> (s + 1);
        for(int j = 1; j <= n; ++j) 
            if(s[j] == '1') E[i].push_back(j);
    }
    for(int i = 1; i <= n; ++i) bfs(i, dis[i]);
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> p[i];
    ans.push_back(p[1]);
/*    for(int i = 1; i <= n; ++i) {*/
        //for(int j = 1; j <= n; ++j) cout << dis[i][j] << " ";
        //cout << endl;
    /*}*/
    for(int i = 3, lst = 1; i <= m; ++i) {
        if(dis[ans.back()][p[i]] < i - lst) ans.push_back(p[i - 1]), lst = i - 1;
    }
    ans.push_back(p[m]);
    cout << ans.size() << endl;
    for(int v : ans) cout << v << " ";

}
