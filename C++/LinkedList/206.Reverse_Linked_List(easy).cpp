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
    原地反转链表：方法1.递归
    1. 递归结束条件：如果head为空或者链表只有1个节点，不需要反转，直接返回；
    2. 当head->next之后的节点已经反转好了，将新的头结点保存为new_head；
    3. 此时，头节点指向新链表的尾节点，需要将新链表的尾节点指向头节点（反转head和head->next），head->next->next = head；
    4. 将头节点的next赋为空；
    5. 返回新链表的头节点；
    */
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};



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
    原地反转链表：方法2.迭代
    1. 递归结束条件：如果head为空或者链表只有1个节点，不需要反转，直接返回；
    2. 使用三个指针，每次将当前指针指向前一个位置的指针，然后将三个指针同时向后移动一位；
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        while(head){
            ListNode* head_next = head->next;
            head->next = new_head;
            new_head = head;
            head = head_next;
        }
        return new_head;
    }
};