#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
int n, w, h;
vector<pii> v(5005);
map<pii, int> p;
int dp[5005], res[5005];

int main() {
    cin >> n >> w >> h;

    for(int i = 1; i <= n; ++i)  {
        cin >> v[i].first >> v[i].second;
        p[v[i]] = i;
    }

    sort(v.begin() + 1, v.begin() + n + 1, [](pii p1, pii p2) {
                return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
            });

    int Max = 0, pos = 0;
    for(int i = 1; i <= n; ++i) {
        if(v[i].first <= w || v[i].second <= h) continue;
        //cout << v[i].first << " " << v[i].second << " " << i << endl;
        for(int j = i - 1; j >= 0; j--) {
            //cout << "***" << i << " " <<  v[j].first << " " <<  v[j].second << endl;
            if(v[i].first > v[j].first && v[i].second > v[j].second) {
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    res[i] = j;
                }
                if(dp[i] > Max) {
                    Max = dp[i];
                    pos = i;
                }
            }
        }
    }


    cout << Max << endl;
    //cout << Max << " " << pos <<  endl;
    if(Max == 0) return 0;
    //cout << Max << " " << pos << endl;
    vector<int> ans;
    for(int i = 0, x = pos; i < Max; x = res[x], ++i) ans.push_back(p[v[x]]);

    for(int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << " ";
    cout << endl;
}
