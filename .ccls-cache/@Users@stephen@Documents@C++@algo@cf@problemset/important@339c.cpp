#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m, w[10], idx = 0, cnt = 0;
int e[105], sum[2];
bool flag = false;
vector<int> ans;

void dfs(int u, vector<int> cur) {
    if(flag) return;
    idx++;
    if(idx == m) { flag = true; ans = cur; return; }
    cur.push_back(u);
    for(int i = 1; i <= 10; ++i) {
        if(flag) return;
        if(u != i && sum[idx % 2] + i > sum[(idx + 1) % 2]) {
            sum[idx % 2] += i; dfs(i);  
        }
    }
}

int main() {
    string s;
    cin >> s >> m;

    for(int i = 0; i <= 9; ++i) {
        w[i + 1] = s[i] - '0';
    }

    for(int i = 1; i <= 10; ++i) {
        if(flag) break;
        sum[1] = i; sum[0] = 0; idx = 0;
        dfs(i);
    }

    cout << (flag ? "YES" : "NO") << endl;
}
