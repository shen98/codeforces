#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

const int N = 2e5 + 5;
int n;
unordered_map<int, int> cnt;
int a[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    int Max = 0, e = 0;
    for(int i = 1; i <= n; ++i) {
        cnt[a[i]] = cnt[a[i] - 1] + 1;
        if(cnt[a[i]] > Max) {
            Max = cnt[a[i]];
            e = a[i];
        }
    }

    //cout << Max << " " << e << endl;
    cout << Max << endl;
    int s = e - Max + 1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == s) {
            cout << i << " ";
            s++;
        }
        if(s > e) break;
    }
    
}
