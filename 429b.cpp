#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1005;

ll a[N][N], n, m, b[N][N], c[N][N], d[N][N], e[N][N];


int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) cin >> a[i][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            //b[i][j] = max(b[i - 1][j], b[i][j - 1]) + a[i][j];
            b[i][j] = max(b[i - 1][j], b[i][j - 1]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) 
            c[i][j] = max(c[i + 1][j], c[i][j - 1]) + a[i][j];
            //c[i][j] = max(c[i + 1][j], c[i][j - 1]) + a[i][j];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 1; --j) 
            d[i][j] = max(d[i - 1][j], d[i][j + 1]) + a[i][j];
    }

    for(int i = n; i >= 1; --i) {
        for(int j = m; j >= 1; --j) 
            e[i][j] = max(e[i + 1][j], e[i][j + 1]) + a[i][j];
    }

    ll ans = 0;
    for(int i = 2; i < n; ++i) {
        for(int j = 2; j < m; ++j) {
            ans = max(max(b[i][j - 1] + c[i + 1][j] + d[i - 1][j] + e[i][j + 1], 
                    b[i - 1][j] + c[i][j - 1] + d[i][j + 1] + e[i + 1][j]), ans);
        }
    }

    cout << ans << endl;
    return 0;
}
