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
    递归反转链表
    */
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
    /*
    判断是否是回文链表：
    1. 使用快慢指针找到链表中点，将链表断开；
    2. 将后半部分链表反转；
    3. 比较两个链表的相同位置的值是否一致；
    */
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = reverseList(slow->next);
        slow->next = NULL;
        while(head && right){
            if(head->val != right->val) return false;
            head = head->next;
            right = right->next;
        }
        return true;
    }
};