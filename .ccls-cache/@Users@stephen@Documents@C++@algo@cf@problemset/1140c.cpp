#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 300005;

int n, k;
pii a[N];

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n, [](pii p1, pii p2){
                return p1.second < p2.second;
            });

    set<pii> s;
    ll ans = 0, cur = 0;
    for(int i = n - 1; i >= 0; --i) {
        s.emplace(a[i].first, i);
        cur += a[i].first;
        while(s.size() > k) {
            auto it = s.begin();
            cur -= it->first;
            s.erase(it);
        }

        ans = max(ans, cur * a[i].second);
    }

    cout << ans << endl;
    return 0;
}
