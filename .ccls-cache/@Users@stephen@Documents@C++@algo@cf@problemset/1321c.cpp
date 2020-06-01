#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int s;
    cin >> s;
    vector<int> v(s + 2, -2);

    string str;
    cin >> str;
    for(int i = 0; i < s; ++i) v[i + 1] = str[i] - 'a';

    for(int k = 25; k >= 0; --k) {
        for(int i = 1; i < v.size() - 1; ++i) {
            if(v[i] == k && (v[i - 1] == k - 1 || v[i + 1] == k - 1)) {
                v.erase(v.begin() + i);
                i--;
            }
        }
        for(int i = v.size() - 1; i >= 1; --i) {
            if(v[i] == k && (v[i - 1] == k - 1 || v[i + 1] == k - 1)) {
                v.erase(v.begin() + i);
                i++;
            }
        }
    }

    cout << s - (v.size() - 2) << endl;
    return 0;
}
