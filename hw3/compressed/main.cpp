#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxN = 100;

int loadString(char *str, int max) {
    int i = 0;
    char temp;
    temp = fgetc(stdin);

    while (temp != EOF)
    {
        if (i == maxN)
        {
            str[i-1] = '\0';
            break;
        }

        if (temp != '\n') {
            str[i] = temp;
            i++;
        } else {
            str[i] = '\0';
            break;
        }
        temp = fgetc(stdin);
    }
    return i;
}

char *unpack(char *packed, int len) {
    char unpacked[len];
    char repeater[len];
    char inner[len];
    int innerLen;
    int repeat;
    char t;
    char ob = '(', cb = ')';
    int i;
    int d = 0;
    int l = 0;
    int j = 0;
    int u = 0;

    for(i = 0; i < len; i++) {
        t = packed[i];
        if (t >= 65 && t <= 90 && l == 0)
        {
            // t is capital letter on top level
            unpacked[u] = t;
        } else if(t >= 30 && t <= 39) {
            // t is digit
            // todo - build repeater
            repeater[d++] = t;
        } else if(t == ob ) {
            if(l == 0) {
                // packed string start
                repeater[d] = '\0';
                d = 0; // reset repeater
                j = 0;
                repeat = atoi(repeater);
            } else {
                inner[j++] = t;
            }
            l++;
        } else if(t == cb ) {
            l--;
            if(l == 0) {
                // packed string start
                inner[j] = '\0';
                j = 0;
            } else {
                inner[j++] = t;
            }
        }
    }
    return unpacked;
}

int main() {
    char str[maxN];
    int l = loadString(str, maxN);
    cout << str << ' ' << l << endl;
    return 0;
}