


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<stdarg.h>

#define memset_s(buffer, sizea, value, sizeb) memset(buffer, value, sizea)
#define sprintf_s(_buffer, len, fmt, args...) sprintf(_buffer, fmt, args)

/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode {
    int val;
    struct ListNode *next;
} NODE_S;

/* 解法二，链表merge */
void InsertAfterNode(NODE_S *pre, NODE_S *insert)
{
    insert->next = pre->next;
    pre->next = insert;
    return;
}

/* headDst的头结点值为最小值 */
void mergeList(NODE_S *headDst, NODE_S *headSrc)
{
    NODE_S *curDstNode = NULL;
    NODE_S *nextDstNode = NULL;
    NODE_S *curSrcNode = NULL;
    NODE_S *nextSrcNode = NULL;

    curDstNode = headDst;
    curSrcNode = headSrc;
    while (curDstNode) {
        nextDstNode = curDstNode->next;
        if (curSrcNode == NULL) {
            /* 原来的链表已经不存在，拼接停止 */
            break;
        }
        if (nextDstNode == NULL) {
            /* 链表拼接 */
            curDstNode->next = curSrcNode;
            break;
        }

        if (nextDstNode->val <= curSrcNode->val) {
            /* 查找第一个比节点值大的前驱结点 */
            curDstNode = nextDstNode;
            continue;
        }
        
        /* 找到第一个符合插入条件的节点,将所有原链表小于nextDstNode的节点插入 */
        while (curSrcNode && (curSrcNode->val <= nextDstNode->val)) {
            nextSrcNode = curSrcNode->next;
            InsertAfterNode(curDstNode, curSrcNode);
            curDstNode = curSrcNode;
            curSrcNode = nextSrcNode;
        } 
    }
    return;
}

NODE_S* copyList(NODE_S *head)
{
    NODE_S headTmp;
    NODE_S *curNode = NULL;
    NODE_S *curNodeTemp = NULL;
    NODE_S *headTempTail = NULL;

    curNode = head;
    (void)memset_s(&headTmp, sizeof(NODE_S), 0, sizeof(NODE_S));
    headTempTail = &headTmp;
    while (curNode) {
        curNodeTemp = (NODE_S*)malloc(sizeof(NODE_S));
        //(void)memset_s(curNodeTemp, sizeof(NODE_S), 0, sizeof(NODE_S));
        curNodeTemp->val = curNode->val;
        InsertAfterNode(headTempTail, curNodeTemp);
        curNode = curNode->next;
        headTempTail = headTempTail->next;
    }
    return headTmp.next;
}

int getMinInt()
{
    unsigned int a = (unsigned int)(~0);
    return (0 - a/2);
}

struct ListNode* mergeKLists1(struct ListNode** lists, int listsSize){
    int i;
    NODE_S listHead;
    NODE_S *listHeadCur = NULL;
    NODE_S *curNode = NULL;

    (void)memset_s(&listHead, sizeof(NODE_S), 0, sizeof(NODE_S));
    listHead.val = getMinInt();
    for (i = 0; i < listsSize; i++) {
        listHeadCur =  copyList(lists[i]);
        mergeList(&listHead, listHeadCur);
    }
    return listHead.next;
}

struct ListNode* mergeKLists(struct ListNode **lists, int listsSize){
    int i;
    NODE_S listHead;
    NODE_S *listHeadCur = NULL;
    NODE_S *curNode = NULL;

    (void)memset_s(&listHead, sizeof(NODE_S), 0, sizeof(NODE_S));
    listHead.val = getMinInt();
    for (i = 0; i < listsSize; i++) {
        listHeadCur = copyList(lists[i]);
        mergeList(&listHead, listHeadCur);
    }
    return listHead.next;
}


