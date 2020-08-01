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
    使用一个指针进行遍历：
    1. 如果没有元素或者只有1个元素，直接返回；
    2. 遍历链表，当下一个元素与当前元素相等时，指针的next指向next的next，用以删除重复的元素，直到下一个元素与当前元素不相等为止；
    3. 指针指向下一个元素（与当前元素不相等的第一个元素）；
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = head;
        while(newHead && newHead->next){
            if(newHead->next->val==newHead->val){
                newHead->next = newHead->next->next;
            }
            else{
                newHead = newHead->next;
            }
        }
        return head;
    }
};