#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, double> pdd;
struct tmp { int x, y, num; };
const int N = 1005;
int n, k;
vector<tmp> vec(N);
int r[N], t[N];
int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        vec[i] = { x, y, i};
        //cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end(), [](tmp p1, tmp p2) {
                return p1.y > p2.y;
            });

    cin >> k;
    for(int i = 1; i <= k; ++i) cin >> r[i];

    int cnt = 0, ans = 0, Min = 1e9, pos = -1;
    for(int i = 0; i < n; ++i) {
        //cout << "***" << i << " " << vec[i].second << endl;
        for(int j = 1; j <= k; ++j) {
            if(vec[i].x <= r[j] && r[j] < Min) {
                pos = j;
                Min = r[j];
            }
        }
        if(pos != -1) {
            cnt++;
            ans += vec[i].y;
            t[vec[i].num] = pos;
            r[pos] = 0;
            pos = -1;
            Min = 1e9;
        }
    }

    cout << cnt << " " << ans << endl;
    for(int i = 1; i <= n; ++i) {
        if(t[i] != 0) cout << i << " " << t[i] << endl;
    }
}
