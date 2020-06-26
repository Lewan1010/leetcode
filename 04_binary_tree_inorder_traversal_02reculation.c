


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。-linked-list
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int nodeIsVisited(struct TreeNode **visitedArr, int visitedSize, struct TreeNode *node)
{
    int i;
    for (i = 0; i < visitedSize; i++) {
        if (node == visitedArr[i]) {
            return 1;
        }
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodeNum = 0;
    int nodeStackNum = 0;
    int visitednodeNum = 0;
    int *orderNums = NULL;
    struct TreeNode* curNode = NULL;
    struct TreeNode* curLeft = NULL;
    struct TreeNode* curTmp = NULL;
    int visited[1000] = {0};
    struct TreeNode *nodeStack[1000] = {0};
    struct TreeNode *visitedNodes[1000] = {0};
    orderNums = (int*)malloc(1000 * sizeof(int));
    memset(orderNums, 0, (sizeof(int) *1000));

    curNode = root;
    nodeStackNum = 0;
    visitednodeNum = 0;
    nodeStack[nodeStackNum++] = root;
    while (nodeStackNum > 0 && curNode) {
        curNode = nodeStack[nodeStackNum - 1];
        curLeft = curNode->left;
        while(curLeft && !nodeIsVisited(visitedNodes, visitednodeNum, curLeft)) {
            nodeStack[nodeStackNum++] = curLeft;
            curLeft = curLeft->left;
        }
        nodeStackNum--;
        curTmp = nodeStack[nodeStackNum];
        orderNums[nodeNum++] = curTmp->val;
        visitedNodes[visitednodeNum++] = curTmp;
        if (curTmp->right) {
            nodeStack[nodeStackNum++] = curTmp->right;
        }
    }
    *returnSize = nodeNum;
    return orderNums;
}
