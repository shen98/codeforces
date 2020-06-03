#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int m = v[0];
    for(int i = 1; i < n; ++i) 
        m = __gcd(m, v[i]);
    int ans = v[n - 1] / m;
    ans -= n;
    cout << (ans % 2 ? "Alice" : "Bob");
    return 0;
}
