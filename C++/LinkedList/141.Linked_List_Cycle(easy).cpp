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
    判断链表是否有环，使用快慢指针
    快指针每次走两步，慢指针每次走一步，看是否可以碰面；主要关注边界情况
    */
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};