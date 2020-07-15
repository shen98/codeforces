#include <iostream>
#include <vector>
using namespace std;

char w[15];
int m, ans[1005];

void dfs(int n, int m, int s, bool t, int p, vector<int> a) {
    //cout << n << " " << p  << " " << t << endl;
    if(m == 0) {
        cout << "YES\n";
        for(auto b : a) cout << b << " ";
        exit(0);
    }
    if(t) {
        for(int i = 1; i <= 10; ++i) {
    //cout << n << endl;
            //cout << a[i] << endl;
            if(i == p || s + i <= 0 || w[i] == '0') continue;
            a.push_back(i);
            dfs(i, m - 1, s + i, !t, i, a);
            a.pop_back();
        }
    } else {
        for(int i = 1; i <= 10; ++i) {
            //cout << i << " " <  << endl;
            if(i == p || s - i >= 0 || w[i] == '0') continue;
            //cout << "***" << i << endl;
            a.push_back(i);
            dfs(i, m - 1, s - i, !t, i, a);
            a.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> (w + 1);

/*    for(int i = 1; i <= 10; ++i) cout << a[i] << " ";*/
    /*cout << endl;*/
    cin >> m;

    dfs(0, m, 0, 1, 0, {});
    cout << "NO\n";
}
