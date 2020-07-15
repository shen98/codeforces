#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 1e6 + 5;

string s;
int a;
vector<string> v[N];

void dfs(int d = 0) {
    int b = s.find(',', a);
    v[d].push_back(s.substr(a, b - a));
    a = b + 1;
    b = s.find(',', a);
    int c = stoi(s.substr(a, b -  a));
    a = b + 1;
    while(c--) dfs(d + 1);
}

int main() {
    cin >> s;
    s += ',';
    while(a < s.size()) dfs();

    int d = 999999;
    while(!v[d].size()) --d;
    cout << d + 1 << endl;

    for(int i = 0; i <= d; ++i) {
        for(auto s : v[i]) cout << s <<  " ";
        cout << endl;
    }
}
