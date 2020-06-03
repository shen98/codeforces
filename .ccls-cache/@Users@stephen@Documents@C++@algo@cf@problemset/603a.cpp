#include <iostream>
#include <string>
using namespace std;

const int N = 100005;

int n, ans;
int a[N], b[N];
string s;

int main() {
    cin >> n;
    cin >> s;

    int r[] = {0, 0};

    for(int i = 0; i < n; ++i) {
        int t = s[i] - '0';
        r[t] = max(t, r[!t] + 1);
    }

    cout << min(max(r[0], r[1]) + 2, n) << endl;
    return 0;
}
