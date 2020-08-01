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
    分隔链表：
    定义两个节点small_head和large_head，前者作为头节点存储小于x的节点，后者作为头节点存储大于等于x的节点，最后进行拼接；
    注意结果链表的尾部应该为null；
    */
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0);
        ListNode* small_head = &node1;
        ListNode node2(0);
        ListNode* large_head = &node2;
        while(head){
            if(head->val<x){
                small_head->next = head;
                small_head = small_head->next;
            }
            else{
                large_head->next = head;
                large_head = large_head->next;
            }
            head = head->next;
        }
        small_head->next = node2.next;
        large_head->next = NULL;
        return node1.next;
    }
};