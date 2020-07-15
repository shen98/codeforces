#include <iostream>

using namespace std;

int n, m;
int l[20], r[20], ll[20], rr[20];

int main() {
    cin >> n >> m;
    int top = n;
    bool flag = 0;
    for(int i = n; i >= 1; --i) {
        string s;
        cin >> s;
        l[i] = INT_MAX;
        bool f = 0;
        for(int j = 1; j <= m; ++j) {
            if(s[j] == '1') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
                f = 1;
            }
        }
        if(r[i] == 0) l[i] = m + 1;
        if(f) flag = 1;
        if(!f && !flag) top = i - 1;
    }

    //cout << top << endl;
    ll[1] = 2 * r[1] + 1;
    rr[1] = m + 2;
    int i = 2;
    for(; i < top; ++i) {
        ll[i] = min(ll[i - 1] + r[i] * 2, rr[i - 1] + m + 1) + 1;
        rr[i] = min(ll[i - 1] + m + 1, rr[i - 1] + (m - l[i] + 1) * 2) + 1;
    }

/*    for(int i = 1; i <= n; ++i) cout << l[i] << " " << r[i] << endl;*/
    /*for(int i = 1; i <= n; ++i) cout << ll[i] << " " << rr[i] << endl;;*/
    if(top == 1) cout << r[top] << endl;
    else cout << min(ll[top - 1] + r[top], rr[top- 1] + (m - l[top] + 1)) << endl;
}
