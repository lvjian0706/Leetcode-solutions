/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
        head->next = nullptr;
        return new_head;
    }
    /*
    重排列链表：将后半部分的链表倒序插入到前半部分链表中；
    1. 使用快慢指针找到后半部分链表；
    2. 反转后半部分链表；
    3. 将右半部分链表插入到左半部分链表中；
    */
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right_half = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* new_head = head;
        while(new_head && right_half){
            ListNode* temp = right_half->next;
            right_half->next = new_head->next;
            new_head->next = right_half;
            right_half = temp;
            new_head = new_head->next->next;
        }
        /*
        当右半部分链表还有一个元素没有插入进去时，单独处理；
        */
        if(right_half){
            right_half->next = new_head->next;
            new_head->next = right_half;
        }
    }
};