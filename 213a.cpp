#include <iostream>
#include <vector>
using namespace std;

const int N = 205;

int n, c[N], deg[N], cdeg[N], ki, ai;
vector<int> G[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    for(int i = 1; i <= n; ++i) {
        cin >> ki;
        for(int j = 1; j <= ki; ++j) {
            cin >> ai;
            G[ai].push_back(i);
            deg[i]++;
        }
    }

    int r = 1 << 20;

    for(int s = 1; s <= 3; ++s) {
        memcpy(cdeg, deg, sizeof deg);

        int cs = s, m = 0, cr = 0;
        while(1) {
            //cout << s << endl;
            while(1) {
                bool found = false;
                for(int i = 1; i <= n; ++i) {
                    //cout << cdeg[i] << " " << cs << endl;
                    if(cdeg[i] == 0 && c[i] == cs) {
                        //cout << 11 << endl;
                        cr++;
                        m++;
                        for(int j : G[i]) cdeg[j]--;
                        cdeg[i]--;
                        found = true;
                        break;
                    }
                }
                if(!found) break;
            }
            if(m < n) { cs = cs % 3 + 1; cr++; }
            else break;
        }
        
        r = min(r, cr);
    }

    cout << r << endl;
}
/*const int N = 205;*/
//int n, ans = 0;
//int a[N];
//bool vs[N];
//vector<int> cur;
//vector<int> ch[N], fa[N];

//int t[4][4];

//void dfs(int u, int p, int tot) {
    //for(int i = 1; i <= 3; ++i) {
        //if(i == u) break;
        //for(int tmp : cur) {
            //for(int c : ch[u]) {
                //bool f = 1;
                //for(int p : fa[c]) if(!vs[p]) { f = 0; break; }

            //}
        //}
        //for(int c : ch[u]) {

            //for()
        //}
    //}
//}

//int main() {
    //t[1][2] = 1;
    //t[1][3] = 2;
    //t[2][1] = 2;
    //t[2][3] = 1;
    //t[3][1] = 1;
    //t[3][2] = 2;

    //cin >> n;
    //for(int i = 1; i <= n; ++i) cin >> a[i];

    //for(int i = 1; i <= n; ++i) {
        //int k;
        //cin >> k;
        //if(k == 0) cur.push_back(i);
        //for(int j = 1; j <= k; ++j) {
            //int v;
            //cin >> v;
            //ch[v].push_back(i);
            //fa[i].push_back(v);
        //}
    //}
/*}*/
