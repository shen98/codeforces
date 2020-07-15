#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
bool cmp(pii p1, pii p2) {
    return abs(p1.first) < abs(p2.first) ||  (abs(p1.first) == abs(p2.first) && abs(p1.second) < abs(p2.second));
}
const int N = 1e5 + 5;
int n, ans = 0;
vector<pii> v(N);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> v[i].first >> v[i].second;
        if(v[i].first == 0 || v[i].second == 0) ans += 4;
        else ans += 6;
    }

    sort(v.begin(), v.begin() + n + 1, cmp);
/*    sort(v.begin(), v.begin() + n, [](pii& p1, pii& p2) {*/
                //return abs(p1.first) + abs(p1.second) < abs(p2.first) + abs(p2.second);
            /*});*/


    cout << ans << endl;

    for(int i = 1; i <= n; ++i)  {
        if(v[i].first != 0) {
            cout << 1 << " " << abs(v[i].first) << " " << (v[i].first > 0 ? "R" : "L") << endl;
        }

        if(v[i].second != 0) {
            cout << 1 << " " << abs(v[i].second) << " " << (v[i].second > 0 ? "U" : "D") << endl;
        }

        cout << 2 << endl;

        if(v[i].first != 0) {
            cout << 1 << " " << abs(v[i].first) << " " << (v[i].first > 0 ? "L" : "R") << endl;
        }

        if(v[i].second != 0) {
            cout << 1 << " " << abs(v[i].second) << " " << (v[i].second > 0 ? "D" : "U") << endl;
        }

        cout << 3 << endl;
    }
}
