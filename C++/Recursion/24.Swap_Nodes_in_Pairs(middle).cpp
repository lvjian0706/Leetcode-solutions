/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    两两交换链表中相邻的节点：递归
    1. 如果链表长度小于2，不用交换直接返回；
    2. 先交换head->next->next后边的链表（只留前两个）；
    3. 定义new_head（也就是结果链表的头节点）为head->next，head指向交换完的head->next->next后边链表的头指针，new_head指向head；
    */
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = swapPairs(head->next->next);
        ListNode* new_head = head->next;
        head->next = temp;
        new_head->next = head;
        return new_head;
    }
};