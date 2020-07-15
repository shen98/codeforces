#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
int n, c1, c2, c3;
queue<pii> q1;
queue<pii> q2;
int c[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        c[i] = c[i - 1] + 20;
        if(i == 1) { q1.emplace(t, i); q2.emplace(t, i); }
        else {
            int idx;
            while(!q1.empty()) {
                idx = q1.front().second;
                int tmp = q1.front().first;
                if(t - tmp < 90) break;
                q1.pop();
            }
            q1.emplace(t, i);
            c[i] = min(c[i], c[idx - 1] + 50);

            idx = 0;
            while(!q2.empty()) {
                idx = q2.front().second;
                int tmp = q2.front().first;
                if(t - tmp < 1440) break;
                q2.pop();
            }
            q2.emplace(t, i);
            c[i] = min(c[i], c[idx - 1] + 120);
        }

        cout << c[i] - c[i - 1] << endl;
    }

/*    for(int i = 1; i <= n; ++i) cout << c[i] << " ";*/
    /*cout << endl;*/
}
