


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

/* 解法一，排序插入 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} NODE_S;

/* 解法一，排序插入 */
void InsertAfterNode(NODE_S *pre, NODE_S *insert)
{
    insert->next = pre->next;
    pre->next = insert;
    return;
}

NODE_S* GetKeyPreNode(NODE_S *head, int value)
{
    NODE_S *curNode = NULL;
    NODE_S *preNode = NULL;

    preNode = head;
    curNode = head;
    while (curNode) {
        if (curNode->val > value) {
            break;
        } else {
            preNode = curNode;
        }
        curNode = curNode->next;
    }
    return preNode;
}

void AddNode(NODE_S* head, int value)
{
    int i;
    NODE_S *curNode = NULL;
    NODE_S *curNodePre = NULL;
    curNode = (NODE_S*)malloc(sizeof(NODE_S));
    (void)memset_s(curNode, sizeof(NODE_S), 0, sizeof(NODE_S));

    curNodePre = GetKeyPreNode(head, value);
    if (curNodePre == NULL) {
        /* not exsists */
       return;
    }
    curNode->val = value;
    InsertAfterNode(curNodePre, curNode);
    return;
}

int getMinInt()
{
    unsigned int a = (unsigned int)(~0);
    return (0 - a/2);
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i;
    NODE_S listHead;
    NODE_S *listHeadCur = NULL;
    NODE_S *curNode = NULL;

    (void)memset_s(&listHead, sizeof(NODE_S), 0, sizeof(NODE_S));

    listHead.val = getMinInt();
    for (i = 0; i < listsSize; i++) {
        listHeadCur =  lists[i];
        curNode = listHeadCur;
        while (curNode) {
            AddNode(&listHead, curNode->val);
            curNode = curNode->next;
        }
    }
    return listHead.next;
}


