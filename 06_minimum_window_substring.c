#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

https://leetcode-cn.com/problems/minimum-window-substring/submissions/
*/

#define TEST_TRUE    1
#define TEST_FALSE   0
#define MAX_CHAR_NUM 128
void AddCnt(int *cnts, char a, int *totalCnt)
{
    cnts[a]++;
    (*totalCnt)++;
}

void DelCnt(int *cnts, char a, int *totalCnt)
{
    cnts[a]--;
    (*totalCnt)--;
    return;
}

int GetCnt(int *cnts, char a)
{
    return cnts[a];
}

int hasKeyStr(int *strCnt, int *keyStrCnt, int start, int end)
{
    int i;
    int hasKey;

    hasKey = TEST_TRUE;
    for (i = start; i <= end; i++) {
        if (strCnt[i] < keyStrCnt[i]) {
            hasKey = TEST_FALSE;
            break;
        }
    }
    return hasKey;
}
char * minWindow(char * s, char * t){
    
    int i;
    int j;
    int slen;
    int tlen;
    int offset;
    int sublen;
    int flag;
    int keyStart;
    int keyEnd;
    int totalKeyCnt;
    int totalSubStrCnt;
    int keyStrCnt[MAX_CHAR_NUM] = {0};
    int subStrCnt[MAX_CHAR_NUM] = {0};
    char *minSubStr = NULL;

    if (s == NULL) {
        return NULL;
    }
    totalKeyCnt = 0;
    totalSubStrCnt = 0;
    slen = strlen(s);
    tlen = strlen(t);
    keyStart = tlen;
    keyEnd = 0;
    for (i = 0; i < tlen; i++) {
        AddCnt(keyStrCnt, t[i], &totalKeyCnt);
        if (keyStart > t[i]) {
            keyStart = t[i];
        }
        if (keyEnd < t[i]) {
            keyEnd = t[i];
        }
    }
    i = 0;
    j = 0;
    offset = slen;
    sublen = slen;
    flag = TEST_FALSE;
    while (j < slen) {
        while(j < slen) {
            if (GetCnt(keyStrCnt, s[j])) {
                AddCnt(subStrCnt, s[j], &totalSubStrCnt);
            }
            
            if (totalSubStrCnt >= totalKeyCnt && 
                hasKeyStr(subStrCnt, keyStrCnt, keyStart, keyEnd) == TEST_TRUE) {
                break;
            }
            j++;
        }
        while(i < slen) {
            if (GetCnt(keyStrCnt, s[i]) == 0) {
                i++;
                continue;
            }
            
            if (totalSubStrCnt < totalKeyCnt ||
                hasKeyStr(subStrCnt, keyStrCnt, keyStart, keyEnd) != TEST_TRUE) {
                break;
            }

            if (sublen >= (j - i + 1)) {
                sublen = j - i + 1;
                offset = i;
                flag = TEST_TRUE;
            }
            if (GetCnt(keyStrCnt, s[i])) {
                DelCnt(subStrCnt, s[i], &totalSubStrCnt);
            }
            i++;
        }
        j++;
    }

    minSubStr = (char*)malloc(sublen + 1);
    memset(minSubStr, 0, sublen + 1); 
    if (flag == TEST_FALSE) {
        return minSubStr;
    }
    for (i = 0; i < sublen; i++) {
        minSubStr[i] = s[i + offset];
    }
    return minSubStr;
}