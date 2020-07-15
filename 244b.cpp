#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
ll n, ans = 0;
queue<vector<ll>> q;

void bfs() {
    q.push({0, -1, -1});
    //for(int i = 1; i <= 9; ++i) q.push({i, i, -1});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        ll cur = p[0], v1 = p[1], v2 = p[2];

        for(int i = 0; i <= 9; ++i) {
            if(cur == 0 && i == 0) continue;
            ll nx = cur * 10 + i, nv1 = v1, nv2 = v2;
            if(v1 == -1) nv1 = i;
            else if(v2 == -1 && i != v1) nv2 = i;
            else {
                if(i != v1 && i != v2) continue;
            }
            if(nx <= n) { 
                //cout << "***" << nx << " " << v1 << " " << v2 << endl;
                q.push({nx, nv1, nv2});
                ans++;
            }
        }
    }
}

int main() {
    cin >> n;

    bfs();

    cout << ans << endl;
}
