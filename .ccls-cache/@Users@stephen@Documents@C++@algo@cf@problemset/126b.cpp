#include <string>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;

const int N = 1e6 + 5;
char s[N], y[N];
int p[N];

int main() {
    //gets(s + 1);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    p[1] = 0;
    int x = 0;

    for(int i = 2; i <= n; ++i) {
        while(x > 0 && s[x + 1] != s[i])
            x = p[x];
        if(s[x + 1] == s[i]) x++;
        p[i] = x;
    }

    int i = p[n];
    memcpy(y, s + 1, i);
    while(i) {
        y[i] = 0;
        x = 0;
        for(int j = 2; j < n; ++j) {
            while(x && s[j] != y[x]) x = p[x];
            if(s[j] == y[x]) x++;
            if(x == i) { printf("%s", y); return 0; }
        }
        i = p[i];
    }
    printf("Just a legend\n");
/*    for(int i = 1; i <= n; ++i) printf("%d ", p[i]);*/
    /*printf("\n");*/
}
