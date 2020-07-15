#include <iostream>
#include <vector>
using namespace std;

int n, m;
char s[1005][1005];
int t[1005][1005], b[1005][1005], l[1005][1005], r[1005][1005], vs[1005][1005];
vector<int> x, y, c;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '*') t[i][j] = t[i - 1][j] + 1;
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '*') b[i][j] = b[i + 1][j] + 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '*') l[i][j] = l[i][j - 1] + 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 1; --j) {
            if(s[i][j] == '*') r[i][j] = r[i][j + 1] + 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '*') {
                int len = min(min(min(t[i - 1][j], b[i + 1][j]), l[i][j - 1]), r[i][j + 1]);
                //cout << "***" << i << " " << j << " " << len << endl;
                if(len == 0) continue;
                x.push_back(i); y.push_back(j); c.push_back(len);
                for(int w = i - len; w <= i + len; ++w) vs[w][j] = 1;
                for(int h = j - len; h <= j + len; ++h) vs[i][h] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) 
            if(s[i][j] == '*' && !vs[i][j]) { cout << -1 << endl; return 0; }
    }

    cout << x.size() << endl;
    for(int i = 0; i < x.size(); ++i) 
        cout << x[i] << " " << y[i] << " " << c[i] << endl;
    /*for(int i = 1; i <= n; ++i) {*/
        //for(int j = 1; j <= m; ++j) cout << t[i][j] << " ";
        //cout << endl;
    //}
    //cout << endl;
    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) cout << b[i][j] << " ";
        //cout << endl;
    //}
    //cout << endl;
    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) cout << l[i][j] << " ";
        //cout << endl;
    //}
    //cout << endl;
    //for(int i = 1; i <= n; ++i) {
        //for(int j = 1; j <= m; ++j) cout << r[i][j] << " ";
        //cout << endl;
    /*}*/
}
