#include <iostream>
using namespace std;

int n, m, da, db, tn, tm, ans = 0;

int main() {
    cin >> n >> m;
    n--; m--;
    tn = n; tm = m;
    while(tn) { tn /= 7; da++; }
    while(tm) { tm /= 7; db++; }
    da = max(da, 1); db = max(db , 1);
    //cout << da << " " << db << endl;
    if(da + db > 7) { cout << 0; return 0; }

    for(int i = 0; i <= n; ++i) {
        int cnt[8];
        for(int k = 0; k < 8; ++k) cnt[k] = 0;
        int cx = i, d = 0;
        while(cx) { cnt[cx % 7]++; cx /=7; d++; }
        for(int x = da - d; x > 0; --x) cnt[0]++;
        for(int j = 0; j <= m; ++j) {
            //cout << "***" << i << " " << j << endl;
            int tmp[8], cj = j, dj = 0;
            for(int k = 0; k < 8; ++k) tmp[k] = cnt[k];
/*            for(int k = 0; k < 8; ++k) cout << tmp[k] << " ";*/
            /*cout << endl;*/
            while(cj) { tmp[cj % 7]++; cj /= 7; dj++; }
            for(int y = db - dj; y > 0; --y) tmp[0]++;
/*            for(int k = 0; k < 8; ++k) cout << tmp[k] << " ";*/
            /*cout << endl;*/
            for(int k = 0; k < 8; ++k) {
                if(tmp[k] > 1) break;
                if(k == 7) ans++;
            }
        }
    }

    cout << ans << endl;
}
