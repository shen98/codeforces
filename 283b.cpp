#include <iostream>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
int n;
ll a[N], p[2][N];
ll y = 0, x = 1;
bool f = 0, vs[N];

/*void dfs(int u) {*/
    //if(f) return;
    //vs[u] = 1;
    //x += a[u];
    //y += a[u];
    ////cout << "***" << x << " " << y << endl; 
    //if(x <= 0 || x > n) { f = 1; return; }
    //y += a[x];
    //x -= a[x];
    ////cout << "***" << x << " " << y << endl; 
    //if(x <= 0 || x > n) { f = 1; return; }
    //if(!vs[x]) dfs(x);
/*}*/

ll sum(int i, int j) {
    //cout << "***" << i << " " << j << endl;
    if(j <= 0 || j > n) return 0;
    if(p[i][j] != 0) return p[i][j];
    p[i][j] = -1;
    ll r = sum(1 - i, i ? j + a[j] : j - a[j]);
    if(r == -1) return -1;
    return p[i][j] = a[j] + r;
}

/*ll sum(int j) {*/
    //if(j <= 0 || j > n) return 0;
    //if(!p[j]) return p[j];
    //p[j]
/*}*/
int main() {
    cin >> n;
    for(int i = 2; i <= n; ++i) cin >> a[i];

    for(int i = 1; i < n; ++i) {
        a[1] = i;
        p[1][1] = 0;
        cout << sum(1, 1) << endl;
/*        for(int k = 0; k < 2; ++k) {*/
            //for(int j = 1; j <= n; ++j) cout << p[k][j] << " " ;
            //cout << endl;
        /*}*/
/*        f = 0; y = 0; x = 1; */
        //for(int i = 1; i <= n; ++i) vs[i] = 0;
        //dfs(1);
        //if(f) cout << y << endl;
        /*else cout << -1 << endl;*/
    }
}
