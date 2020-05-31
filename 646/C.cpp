#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;


void dfs(int u) {
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> map(N);
        for(int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            map[u].push_back(v);
            map[v].push_back(u);
        }

        if(n == 1) cout << "Ayush" << endl; 
        else if(map[x].size() == 1) { cout << "Ayush" << endl; }
        else {
            if((n - 1) % 2 == 0) cout << "Ashish" << endl;
            else cout << "Ayush" << endl;
        }
    }
    return 0;
}
