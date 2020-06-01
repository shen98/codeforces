#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 200005

struct tmp {
    int x, i;
} a[N];

queue<int> q;
int ans[N];

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x;
        a[i].i = i;
    }
    sort(a + 1, a + n + 1, [](const tmp& t1, const tmp& t2) {
            return t1.x < t2.x;
            });


    int s = 0;
    for(int i = 1; i <= n; ++i) {
        if(q.empty()) {
            s++;
            q.push(i);
            ans[a[i].i] = s;
            continue;
        } 

        int p = q.front();
        if(a[i].x - a[p].x > d) {
            q.pop();
            q.push(i);
            ans[a[i].i] = ans[a[p].i];
        } else {
            s++;
            q.push(i);
            ans[a[i].i] = s;
        }
    }

    cout << s << endl;
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
