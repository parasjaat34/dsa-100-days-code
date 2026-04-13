#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int index[256];
    for (int i = 0; i < 256; i++) index[i] = -1;

    int res = 1000000;
    char ans = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];

        if (index[c] == -1) {
            index[c] = i;
        } else {
            if (index[c] < res) {
                res = index[c];
                ans = c;
            }
        }
    }

    if (ans == -1) printf("-1");
    else printf("%c", ans);

    return 0;
}