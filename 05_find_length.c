


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*

*/

int getMaxCommonLength(int* A, int ASize, int* B, int BSize)
{
    int i;
    int j;
    int temp;
    int maxSubLen;
    int tempMaxSubLen;

    maxSubLen = 0;
    for (i = 0; i < ASize; i++) {
        temp = i;
        tempMaxSubLen = 0;
        j = 0;
        while (j < BSize) {
            if (temp >= ASize) {
                break;
            }
            /* 如果不等，则重置 */
            if (A[temp] != B[j]) {
                temp = i;
                tempMaxSubLen = 0;
            }

            /* 重置后，与新节点A[i](i == temp)比较，如果不重置，则与后续的节点比较 */
            if (A[temp] == B[j]) {
                temp++;
                tempMaxSubLen++;
            }
            maxSubLen = maxSubLen >= tempMaxSubLen ? maxSubLen : tempMaxSubLen;
            j++;
        }
    }

    return maxSubLen;
}

int findLength(int* A, int ASize, int* B, int BSize){
    int maxSubLen;
    int tempMaxSubLen;
    maxSubLen = 0;

    tempMaxSubLen = getMaxCommonLength(A, ASize, B, BSize);
    maxSubLen = getMaxCommonLength(A, ASize, B, BSize);
    maxSubLen = maxSubLen >= tempMaxSubLen ? maxSubLen : tempMaxSubLen;
    return maxSubLen;
}

/*

    printf(" \n");

    for (i = 0; i < maxSubLen; i++) {
        printf(" %d", B[j - maxSubLen + 1 + i]);
    }

{0,0,0,0,0,0,1,0,0,0}
{0,0,0,0,0,0,0,1,0,0}

{1,0,1,0,0,0,0,0,1,1}
{1,1,0,1,1,0,0,0,0,0}
*/

int main()
{
    int A[] = {1,0,1,0,0,0,0,0,1,1};//{1,0,1,1,0,1,1,0,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0};
    int B[] = {1,1,0,1,1,0,0,0,0,0};//{1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0};
    int len = 0;

    len = findLength(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0]));
    printf("\n length:%d", len);
}