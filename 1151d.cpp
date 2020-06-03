#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;

const int N = 100005;

int n;
vector<pii> c(N), v(N);

int main() {
    cin >> n;

    int pos, cur = 0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i].first = a;
        v[i].second = b;
        c[i].first = a - b;
        c[i].second = i;
    }

    sort(c.begin(), c.begin() + n, [](pii p1, pii p2) {
                return p1.first < p2.first;
            });

    ll ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        ans += (n - i - 1) * v[c[i].second].first + i * v[c[i].second].second;
    }

    cout << ans << endl;
    return 0;
}
