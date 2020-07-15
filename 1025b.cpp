#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int N = 150005;
int n;
int a[N], b[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> vec;

    for(int i = 2; i * i <= a[0]; ++i) {
        if(a[0] % i == 0) {
            vec.push_back(i);
            while(a[0] % i == 0) a[0] /= i;
        }
    }
    if(a[0] > 1) vec.push_back(a[0]);

    for(int i = 2; i * i <= b[0]; ++i) {
        if(b[0] % i == 0) {
            vec.push_back(i);
            while(b[0] % i == 0) b[0] /= i;
        }
    }
    if(b[0] > 1) vec.push_back(b[0]);

    bool flag = true;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < vec.size(); ++j) {
            if(a[i] % vec[j] && b[i] % vec[j]) {
                vec.erase(vec.begin() + j);
                j--;
            }
        }
    }

    if(vec.size() == 0) cout << -1 << endl;
    else cout << vec[0] << endl;
    return 0;
}
