//https://leetcode-cn.com/problems/palindrome-number/submissions/

bool isPalindrome(int x){
    int tmp;
    int base;
    long long int xReverse;
    int restNum;
    if (x < 0) {
        return false;
    }
    xReverse = 0;
    tmp = x;
    base = 10;
    while (tmp > 0) {
        /* 获取个位数 */
        xReverse *= base;
        restNum = tmp;
        tmp /= base;
        restNum -= tmp *base;
        xReverse += restNum;
    }
    return xReverse == (long long int)x;
}