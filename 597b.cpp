#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int N = 5e5 + 5;
int n;
int a[N];
vector<pii> v(N);

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin() + 1, v.begin() + n + 1);

    int Max = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(v[i].second > Max) { ans++; Max = v[i].first; }
    }
/*    for(int i = 0; i <= n; ++i) cout << a[i] << " ";*/
    /*cout << endl;*/
    cout << ans << endl;
}
