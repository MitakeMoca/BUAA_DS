#include <stdio.h>
#include <string.h>

char str[105];

int main() {
    gets(str);
    int len = strlen(str);
    int m = 0;
    for(int i = 0; i < len; i++) {
        if(m == 0) {
            if(i == 0 || str[i] != str[i - 1] + 1)
                printf("%c", str[i]);
            else
                m = 1;
        }
        else if(m == 1) {
            if(str[i] == str[i - 1] + 1)
                printf("-"), m = 2;
            else
                printf("%c%c", str[i - 1], str[i]), m = 0;
        } else {
            if(str[i] == str[i - 1] + 1)
                continue;
            else
                printf("%c%c", str[i - 1], str[i]), m = 0;
        }
    }
    
    if(m != 0)
        printf("%c", str[len - 1]);

    return 0;
}