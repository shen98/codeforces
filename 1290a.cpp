#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);

        vector<int> v(n);

        for(int i = 0; i < n; ++i) cin >> v[i];

        int ans = INT_MIN;
        for(int x = 0; x <= k; ++x) {
            int g = INT_MAX;
            for(int y = 0; y <= m - k - 1; ++y) {
                int temp = max(v[x + y], v[x + y + n - m]);
                g = min(g, temp);
            }
            ans = max(ans, g);
        }

        cout << ans << endl;
    }
    return 0;
}
