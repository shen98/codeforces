#include <iostream>
#include <queue>
using namespace std;

const int N = 300005;

queue<int> que;
int cnt[N], c[N];

int main() {
    int n, q;
    cin >> n >> q;

    int total = 0, num = 0;
    for(int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            cnt[x]++;
            total++;
            c[x]++;
            que.push(x);
        } else if(t == 2) {
            total -= cnt[x];
            cnt[x] = 0;
        } else {
            while(x > num) {
                if(que.empty()) break;
                int a = que.front();
                que.pop();
                if(c[a]) c[a]--;
                if(cnt[a] > c[a]) {
                    cnt[a]--;
                    total--;
                }
                num++;
            }
        }

        cout << total << endl;
    }
    return 0;
}
