#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v = { 'R', 'G', 'B' };

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        int r = 0, g = 0, b = 0, ans = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < k; ++j) {
                if(i == 0 && str[j] != v[j % 3]) r++;
                else if(i == 1 && str[j] != v[(j + 1) % 3]) g++;
                else if(i == 2 && str[j] != v[(j + 2) % 3]) b++;
            }
        }
        ans = min(min(r, g), b);

        for(int j = 1; j < n - k + 1; ++j) {
            int pr = r, pg = g, pb = b;
            //cout << r << " " << g << " " << b << endl;
            for(int i = 0; i < 3; ++i) {
                if(i == 0) {
                    r = pb - (str[j - 1] != 'B') + (str[j + k - 1] != v[(k - 1) % 3]);
                    //cout << "***" << b << " " << (str[j - 1] != 'B') << " " << (str[j + k - 1] != v[(k - 1) % 3]) << endl;
                } else if(i == 1) {
                    g = pr - (str[j - 1] != 'R') + (str[j + k - 1] != v[k % 3]);
                } else {
                    b = pg - (str[j - 1] != 'G') + (str[j + k - 1] != v[(k + 1) % 3]);
                }
            }
            ans = min(ans, min(r, min(g, b)));
        }

        cout << ans << endl;
    }
    return 0;
}
