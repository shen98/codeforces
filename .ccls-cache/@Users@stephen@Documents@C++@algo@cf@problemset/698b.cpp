#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int n, root = -1, t, ans;
int p[N], m[N];

void dfs(int v) {
    m[v] = t;
    if(!m[p[v]]) dfs(p[v]);
    else {
/*        cout << "***" << v <<  " " << root << " " << t << endl;*/
    //for(int i = 1; i <= n; ++i) cout << p[i] <<  " ";
    //cout << endl;
        /*for(int i = 1; i <= n; ++i) cout << m[i] << " ";*/
        //cout << endl;
        if(m[p[v]] == t) {
            if(root == -1) 
                ans++, p[v] = v, root = v;
            else if(v != root)
                ans++, p[v] = root;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        if(p[i] == i) root = i;
    }
    for(int i = 1; i <= n; ++i) if(!m[i]) { t++; dfs(i); }
    cout << ans << endl;
    for(int i = 1; i <= n; ++i) cout << p[i] << " ";
    cout << endl;
}
