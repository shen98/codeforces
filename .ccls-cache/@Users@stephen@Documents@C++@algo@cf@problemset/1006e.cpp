#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

vector<int> map[N], order, num(N), a(N);


int dfs(int u) {
    order.push_back(u);

    int s = 1;
    for(auto v : map[u]) {
        s += dfs(v);
    }

    num[u] = s;
    return s;
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        map[p].push_back(i);
    }

    dfs(1);
    for(int i = 0; i < order.size(); ++i) {
        a[order[i]] = i;
    }
/*    for(auto a : order) cout << a << " ";*/
    //cout << endl;
    //for(int i = 1; i <= n; ++i) cout << num[i] << " ";
    /*cout << endl;*/
    for(int i = 0; i < q; ++i) {
        int u, k;
        cin >> u >> k; 
        if(num[u] < k) { cout << -1 << endl; continue; }
        else cout << order[a[u] + k - 1] << endl;
/*        for(int j = 0; j < n; ++j) {*/
            //if(order[j] == u) {
                //cout << order[j + k - 1] << endl;
            //}
        /*}*/
    }




    return 0;
}
