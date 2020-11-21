
//https://leetcode-cn.com/problems/regular-expression-matching/
#define bool unsigned short
#define true  1
#define false 0
#define NULL  0
bool isMatch(char *s, char *p) {
    int i;
    int j;
    int slen;
    int plen;
    bool flag;
    if (s == NULL || p == NULL) {
        return false;
    }
    slen = strlen(s);
    plen = strlen(p);
    if (plen > slen) {
        return false;
    }

    j = 0;
    flag = false;
    for (i = 0; i < plen; i++) {
        if (p[i] == '.') {
            flag = true;
            j++;
        } else if (p[i] == '*') {
            if (i > 0) {
                /* 找到下一个与p[i - 1]不同的 */
                if (p[i - 1] != '.') {
                    while (j < slen && s[j] == p[i - 1]) {
                        j++;
                    }
                }
                flag= true;
            }
        } else {
            if (p[i] != s[j]) {
                flag= false;
            } else {
                flag= true;
            }
            j++;

        }
    }

    if (j != slen) {
        flag = false;
    }
    return flag;
}