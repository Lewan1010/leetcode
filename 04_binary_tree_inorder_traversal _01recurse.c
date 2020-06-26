


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
/* 递归访问 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode* root, int *array, int *num)
{
    if (!root) {
        return;
    }
    traverse(root->left, array, num);
    array[(*num)++] = root->val;
    traverse(root->right, array, num);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodeNum;

    int *orderNums = NULL;

    orderNums = (int*)malloc(1000 * sizeof(int));
    memset(orderNums, 0, (sizeof(int) *1000));
    nodeNum = 0;
    traverse(root, orderNums, &nodeNum);
    *returnSize = nodeNum;
    return orderNums;
}


