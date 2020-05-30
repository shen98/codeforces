#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i] = make_pair(0, m);
    }
    
    cin >> q;
    vector<int> max2(q + 1);
    for(int i = 1; i <= q; ++i) {
        int k;
        cin >> k;
        if(k == 1)  {
            int x, p;
            cin >> x >> p;
            a[x - 1] = make_pair(i, p);
        } else {
            int x;
            cin >> x;
            max2[i] = x;
        }
    }

    for(int i = max2.size() - 2; i >= 0; --i) {
        max2[i] = max(max2[i], max2[i + 1]);
    }

    for(int i = 0; i < n; ++i) {
        cout << max(a[i].second, max2[a[i].first]) << " ";
    }
    cout << endl;

    return 0;
}
