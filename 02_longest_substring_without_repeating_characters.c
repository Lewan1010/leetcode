


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/* 备注：包含了求字串，在明白了滑动窗口扩展，伸缩原理之后，求长度便很容易求得子串，即记录下偏移和长度即可 */
int lengthOfLongestSubstring(char *s) {
    int max;
    int subStringOffset;
    int offset;
    int start;
    int len;
    int end;
    int charArrar[256];
    char maxSubstring[256];

    (void)memset(charArrar, 0, sizeof(charArrar));
    (void)memset(maxSubstring, 0, sizeof(maxSubstring));
    start = 0;
    max = 0;
    len = strlen(s);
    subStringOffset = 0;
    for (end = 0; end < len; end++) {
        /* 滑窗右滑动一格 */
        charArrar[s[end]]++;
        if (charArrar[s[end]]!= 1) {
            /* 包含重复字符，滑窗左边滑动到重复字符的右边 */
            while (s[start] != s[end]) {
                charArrar[s[start]]--;
                start++;
            }
            charArrar[s[start]]--;
            start++;
        }
        offset = end - start + 1;
        if (offset > max) {
            max = offset;
            subStringOffset = start;
        }
        max = (max > (end - start + 1)) ? max :  (end - start + 1);
        printf("\nstart:%d %c %d end %d %c %d max %d", start, s[start], charArrar[s[start]], end, s[end], charArrar[s[end]], max);
    }
    for (start = 0; start < max; start++) {
        maxSubstring[start] = s[subStringOffset + start];
    }
    maxSubstring[start] = 0;
    printf("\n sub %s", maxSubstring);
    return max;
}

int main(int argc, char *argv[])
{
    char buffer[] = "abcabcbb";
    char *ptr = argv[1];
    printf("\n %s max:%d",ptr, lengthOfLongestSubstring(ptr));
    return 0;
}