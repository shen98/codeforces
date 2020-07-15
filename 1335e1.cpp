#include <iostream>

using namespace std;

int t, n;
int a[2005];
int l[30], c[30], r[30];
int main() {
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)  cin >> a[i];
        for(int i = 1; i <= 26; ++i) l[i] = r[i] = c[i] = 0;

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int k = 1; k <= 26; ++k) r[k] = c[k] = 0;
            for(int j = i; j <= n; ++j) r[a[j]]++;
            for(int j = i; j <= n; ++j) {
                r[a[j]]--;
                c[a[j]]++;
                int s = 0, d = 0;
                for(int k = 1; k <= 26; ++k) {
                    s = max(s, 2 * min(l[k], r[k]));
                    d = max(d, c[k]);
                }
                ans = max(ans, s + d);
            }
            l[a[i]]++;
        }

        cout << ans << endl;
    }
}
