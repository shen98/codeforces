#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int t, n, m, ans, x, y;
int a[N], c[N];
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        c[0] = ans = 0;
        for(int i = 1; i <= n; ++i) cin >> a[i], c[i] = 0;
        cin >> m;
        for(int i = 1; i <= m; ++i) cin >> x >> y, c[y] = max(c[y], x);
        for(int i = n - 1; i; --i) c[i] = max(c[i + 1], c[i]);
/*        for(int i = 1; i <= n; ++i) cout << c[i] << " ";*/
        /*cout << endl;*/
        for(int i = 1; i <= n && ~ans;) {
            ++ans;
            int j = i, mx = 0;
            while(1) {
                mx = max(mx, a[j]);
                if(mx > c[j - i + 1]) break;
                ++j;
            }
            if(j == i) ans = -1;
            i = j;
        }
        cout << ans << endl;
    }
}
