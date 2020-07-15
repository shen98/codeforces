#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N], b[N];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 2; i <= n; ++i) {
        for(int j = i - 1; j >= 1; --j) {
            if(a[i] == a[j] + 1) { b[i] = b[j] + 1; break; }
        }
    }

    cout << n - *max_element(b, b + n + 1) - 1 << endl;

    return 0;
}
