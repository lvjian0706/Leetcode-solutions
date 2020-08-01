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
    循环链表：
    1. 首先判断是否是环，使用快慢指针，快指针每次走2步，慢指针每次走1步，看是否相遇，不相遇则返回null；
    2. 如果相遇，设慢指针走了s，则快指针已经走了2s，假设从head到环的入口为a，环的长度为b，则s=nb，快指针比慢指针多走了nb；
    3. 想要计算环的入口a，可以使用两个指针，一个在head处走a步，一个在相遇处走a步，此时，一个指针的位置为a，一个为a+nb，因为有环，所以a=a+nb；
    4. 最终的相遇位置为环的入口；
    */
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                slow = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};