#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

vector<int> a[N];

int n;
int cnt[N];
/*bool ok = true;*/
//bool visited[N];

//void dfs(int u, int p) {
    //visited[u] = true;
    //int num = 0;
    //for(auto v : a[u]) {
        //if(v == u || visited[v]) continue;
        //num++;
        //dfs(v, u);
    //}

    //if(num == 1 && p != 0) ok = false;
/*}*/

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        //a[u].push_back(v);
        //a[v].push_back(u);
    }

    for( int i = 1; i <= n; ++i) {
        if(cnt[i] == 2) { cout << "No" << endl; return 0; }
    }
   
    cout << "YES" << endl;
    //dfs(1, 0);
    //cout << (ok ? "YES" : "NO");
    return 0;
}
