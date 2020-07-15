#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
int n;
int hd[N], d[N], e[N];
bool vs[N];
vector<int> v[N];

void bfs() {
    queue<int> q;
    q.push(1);
    //vs[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        //cout << "***" << u << " " << d[u] << endl;
        for(auto nx : v[u])  {
            if(vs[nx]) continue;
            d[nx] = min(d[nx], d[u] + 1);
            vs[nx] = 1;
            q.push(nx);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i] = i - 1;

    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        v[i].push_back(a);
    }

    for(int i = 2; i <= n; ++i) {
        v[i].push_back(i - 1);
    }

    for(int i = 1; i <= n - 1; ++i) {
        v[i].push_back(i + 1);
    }

    d[1] = 0;
    bfs();

    for(int i = 1; i <= n; ++i) cout << d[i] << " ";
    cout << endl;

    return 0;
}
