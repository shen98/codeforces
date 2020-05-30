#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;

        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int pref = 0, ans = 0;
        for(int i = 0; i < k; ++i) {
            int sum = pref, cnt = i;
            if(sum > p) break;
            for(int j = i + k - 1; j < n; j += k) {
                if(sum + a[j] <= p) {
                    cnt += k;
                    sum += a[j];
                } else break;
            }

            pref += a[i];
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }

    return 0;
}
