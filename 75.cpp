#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int a, b, n;
vector<int> d;

void gcd(int a, int b) {
    d.push_back(0);
    d.push_back(INT_MAX);
    while(a) {
        b %= a; 
        swap(a, b);
    }

    for(int i = 1; i * i <= b; ++i) {
        if(b % i == 0) { d.push_back(i); d.push_back(b / i); }
    }
    d.push_back(b);
}

void check(int& a, int& b) { if(a > b) swap(a, b); }

int main() {
    cin >> a >> b >> n;
    check(a, b);
    gcd(a, b);
    sort(d.begin(), d.end());

/*    for(auto a : d) cout << a << " ";*/
    /*cout << endl;*/
    for(int i = 0; i < n; ++i) {
        int low, high;
        cin >> low >> high;
        if(low > a) cout << -1 << endl;
        else {
            int l = 0, r = d.size() - 1, p = 0;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(d[m] <= high && d[m] >= low) { p = m; l = m + 1; }
                else if(d[m] < low) l = m + 1;
                else if(d[m] > high) r = m - 1;
                //cout << "***" << d[m] << " " << l << " " << r << endl;
            }

            cout << (p == 0 ? -1 : d[p]) << endl;
        }
    }

    return 0;
}
