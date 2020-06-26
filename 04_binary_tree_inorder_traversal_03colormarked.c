


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

/*

官方题解中介绍了三种方法来完成树的中序遍历，包括：

递归
借助栈的迭代方法
莫里斯遍历
在树的深度优先遍历中（包括前序、中序、后序遍历），递归方法最为直观易懂，但考虑到效率，我们通常不推荐使用递归。

栈迭代方法虽然提高了效率，但其嵌套循环却非常烧脑，不易理解，容易造成“一看就懂，一写就废”的窘况。而且对于不同的遍历顺序（前序、中序、后序），循环结构差异很大，更增加了记忆负担。

因此，我在这里介绍一种“颜色标记法”（瞎起的名字……），兼具栈迭代方法的高效，又像递归方法一样简洁易懂，更重要的是，这种方法对于前序、中序、后序遍历，能够写出完全一致的代码。

其核心思想如下：

使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
如果遇到的节点为灰色，则将节点的值输出。

作者：hzhu212
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define WHITE       0
#define GRAY        1
#define INVALID   0xf

typedef struct
{
    unsigned long *addr;
    char color;
}ADDR_COLOR;

ADDR_COLOR* AddrColorPop(ADDR_COLOR *addrColor, int *size)
{
    return &addrColor[--(*size)];
}

void AddrColorPush(ADDR_COLOR *addrColor, int *size, void *addr, char color)
{
    addrColor[*size].addr = (unsigned long *)addr;
    addrColor[*size].color = color;
    (*size)++;
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodeNum = 0;
    int nodeStackNum;
    int *orderNums = NULL;
    ADDR_COLOR nodeStack[1000] = {0};
    struct TreeNode* curNode = NULL;
    ADDR_COLOR *curAddrColor = NULL;
    
    orderNums = (int*)malloc(1000 * sizeof(int));
    memset(orderNums, 0, (sizeof(int) *1000));

    nodeStackNum = 0;
    memset(&nodeStack, 0, sizeof(ADDR_COLOR)*1000);
    AddrColorPush(&nodeStack, &nodeStackNum, root, WHITE);
    while (nodeStackNum > 0) {
        /* pop */  
        curAddrColor = AddrColorPop(&nodeStack, &nodeStackNum);
        curNode = (struct TreeNode*)curAddrColor->addr;
        if (!curNode) {
            continue;
        }

        if (curAddrColor->color == WHITE) {
            /* push 根据LIFO, 将最先访问的放在最后面*/
            AddrColorPush(&nodeStack, &nodeStackNum, curNode->right, WHITE);
            AddrColorPush(&nodeStack, &nodeStackNum, curNode, GRAY);
            AddrColorPush(&nodeStack, &nodeStackNum, curNode->left, WHITE);
        } else {
            orderNums[nodeNum++] = curNode->val;
        }
    }
    *returnSize = nodeNum;
    return orderNums;
}