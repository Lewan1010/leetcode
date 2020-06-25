


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*

给定一个二叉树，原地将它展开为一个单链表。


例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void flatten(struct TreeNode* root){
    struct TreeNode* curNode = NULL;
    struct TreeNode* curLeft = NULL;
    struct TreeNode* curTmp = NULL;
    curNode = root;
    while (curNode) {
        curLeft = curNode->left;
        if (!curLeft) {
            curNode = curNode->right;
            continue;
        }
        curTmp = curLeft;
        while (curTmp->right) {
            curTmp = curTmp->right;
        }
        curTmp->right = curNode->right;
        curNode->right = curLeft;
        curNode->left = NULL;
        curNode = curNode->right;
    }
    return;
}