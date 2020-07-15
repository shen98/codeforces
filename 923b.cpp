#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 100005;

int n;
ll v[N], t[N], sum[N], ans0[N], ans[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i <= n; ++i) cin >> t[i];
    for(int i = 1; i <= n; ++i) sum[i] = t[i] + sum[i - 1];

    for(int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while(l <= r) {
            int m = l + r >> 1;
            if(sum[m] - sum[i - 1] > v[i]) r = m - 1;
            else l = m + 1;
        }

        ans0[r]++; ans0[i - 1]--;
        ans[r + 1] += v[i] - sum[r] + sum[i - 1];
    }

    for(int i = n; i >= 1; --i) {
        ans0[i] += ans0[i + 1];
        ans[i] += ans0[i] * t[i];
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
