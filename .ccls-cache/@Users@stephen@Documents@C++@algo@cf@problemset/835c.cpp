#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, q, mod;

const int N = 105;
int a[N][N][11];

int main() {
    cin >> n >> q >> mod;
    for(int i = 0; i < n; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        a[x][y][s]++;
    }

    for(int k = 0; k < 11; ++k) {
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j < N; ++j) 
                a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] - a[i - 1][j - 1][k];
        }
    }

    for(int i = 0; i < q; ++i) {
        int t, x1, y1, x2, y2, ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        
        for(int k = 0; k < 11; ++k) {
            ans += (a[x2][y2][k] - a[x1 - 1][y2][k] - a[x2][y1 - 1][k] + a[x1 - 1][y1 - 1][k]) * ((k + t) % (mod + 1));
        }

        cout << ans << endl;
    }

    return 0;
}
