#include <iostream>
#include <string>
using namespace std;
const int N = 3e5 + 5;
int n, m, ans = 0;
int hd[N], vs[N], dp[N][30], cur[N], cnt = 0;
struct edge { int to, nx; } e[N];
char s[N];
bool f = 0;
void addEdge(int u, int v) {
    e[++cnt] = (edge) { v, hd[u] };
    hd[u] = cnt;
}

void dfs(int u) {
    //cout << "***" << u << endl;
    if(f) return;
    vs[u] = cur[u] = 1; 
    //cnt[s[u] - 'a']++;

    for(int i = hd[u]; i; i = e[i].nx) {
        int v = e[i].to;
        //cout << "***" << u << " " << v << " " << i << endl;
        if(cur[v]) { f = 1; return; }
/*        if(dp[v][s[v] - 'a']) {*/
            //for(int i = 0; i <= 25; ++i)
                //dp[u][i] = max(dp[u][i], dp[v][i]);
            //continue;
        /*}*/
        if(!vs[v]) {
            dfs(v); 
            //cout << "&&&" << u << " " << v << " " << endl; 
            //cout << endl;
        }
         for(int j = 0; j <= 25; ++j) {
                //cout << dp[u][i] << " ";
                dp[u][j] = max(dp[u][j], dp[v][j]);
                ans = max(ans, dp[u][j]);
         } 
    }

    dp[u][s[u] - 'a']++;
    ans = max(ans, dp[u][s[u] - 'a']);
/*    cout << "***" << u << endl;;*/
    //for(int i = 0; i <= 25; ++i) cout << dp[u][i] << " ";
    //cout << endl;
    /*cout << endl;*/
    cur[u] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> (s + 1);
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        //cout << u << v <<  endl;
        addEdge(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(!vs[i])  {
            dfs(i);
        }
    }

/*    for(int i = 1; i <= n; ++i) {*/
        //for(int j = 0; j <= 25; ++j) cout << dp[i][j] << " ";
        //cout << endl;
    /*}*/
    cout << (f ? -1 : ans) << endl;
}
