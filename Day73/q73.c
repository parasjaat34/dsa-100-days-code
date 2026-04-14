#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }

    char ans = '$';

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            ans = s[i];
            break;
        }
    }

    printf("%c", ans);

    return 0;
}