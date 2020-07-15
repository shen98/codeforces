#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b, ans = 0;
int cnt[11], m[20], d = 0, da = 0;
char s1[20], s2[20];
int main() {
    cin >> s1 >> s2;

    int len1 = strlen(s1), len2 = strlen(s2);

    sort(s1, s1 + len1);

    if(len1 < len2) {
        reverse(s1, s1 + len1);
        //cout << s1 << endl;
    } else {
        for(int i = 0; i < len1; ++i) {
            for(int j = len1 - 1; j >= i; --j) {
                char tmp[20];
                strcpy(tmp, s1);
                swap(s1[i], s1[j]);
                sort(s1 + i + 1, s1 + len1);
                if(strcmp(s1, s2) > 0) {
                    strcpy(s1, tmp);
                    continue;
                } else break;
            }
            //cout << s1 << endl;
        }
    }
    cout << s1 << endl;
}
