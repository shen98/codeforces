#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 505;
int n, m, ans = 0;
int w[N];

stack<int> s;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) cin >> w[i];

    for(int i = 1; i <= m; ++i) {
        vector<int> tmp;
        int b;
        cin >> b;
        while(!s.empty()) {
            int a = s.top();
            if(a != b) {
                tmp.push_back(a);
                ans += w[a];
                s.pop();
            } else { s.pop(); break; }
        }
        for(int i = tmp.size() - 1; i >= 0; --i) s.push(tmp[i]);
        s.push(b);
/*        for(auto a : tmp) cout << a << " ";*/
        //cout << endl;
        /*cout << "***" << ans << endl;*/
    }

    cout << ans << endl;
}
