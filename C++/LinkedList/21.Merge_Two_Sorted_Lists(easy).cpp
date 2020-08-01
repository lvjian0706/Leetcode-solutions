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
    合并有序链表：类似归并排序的思路
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode node(0);
        ListNode* new_head = &node;
        while(l1 && l2){
            if(l1->val <= l2->val){
                new_head->next = l1;
                l1 = l1->next;
            }
            else{
                new_head->next = l2;
                l2 = l2->next;
            }
            new_head = new_head->next;
        }
        while(l1){
            new_head->next = l1;
            l1 = l1->next;
            new_head = new_head->next;
        }
        while(l2){
            new_head->next = l2;
            l2 = l2->next;
            new_head = new_head->next;
        }
        return node.next;
    }
};