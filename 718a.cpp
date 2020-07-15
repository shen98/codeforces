#include <iostream>
using namespace std;

const int N = 2e5 + 5;
int n, t, l, f = 0;
char s[N];

int main() {
    cin >> n >> t >> (s + 1);

    s[0] = '0';
    for(int i = 0; s[i]; ++i) {
        if(s[i] == '.') f = 1;
        else if(s[i] >= '5' && f) {
            int j = i - 1, k = 0;
            for(;s[j + 1] >= '5' && k < t; k++, --j) {
                if(s[j] == '.') {
                    for(int c = 1, p = j - 1; p >= 0; --p) {
                        s[p]+=c;
                        if(s[p] > '9') s[p] -= 10, c = 1;
                        else c = 0;
                    }
                    s[j] = 0; break;
                } else 
                    s[j]++;
            }
            s[j + 2] = 0;
            cout << (s[0] == '0' ? s + 1 : s);
            return 0;
        }
    }
    cout << s + 1 << endl;
}
