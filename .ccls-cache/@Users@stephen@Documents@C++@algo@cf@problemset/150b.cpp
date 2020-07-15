#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;
int n, m, k, ans;

bool check(vector<int> q) {
    for(int i = 0; i < (q.size() - 1) / 2; ++i) {
        if(q[i + 1] != q[q.size() - 1 - i]) return false;
    }

    return true;
}

void dfs(vector<int> pre, int t) {
    //cout << "***" << pre.size() << endl;
    if(t == k) { ans = (ans + 1) % mod; return; }
    for(int i = 1; i <= m; ++i) {
        vector<int> nx = pre;
        if(nx.size() == k) nx.erase(nx.begin());
        if(nx.size() < (k + 1) / 2) {
            nx.push_back(i);
            dfs(nx, t + 1);
        } else {
            if(check(nx) && i == nx[0]) {
                nx.push_back(i);
                dfs(nx, t + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    dfs({}, 0);

    cout << ans << endl;
}
