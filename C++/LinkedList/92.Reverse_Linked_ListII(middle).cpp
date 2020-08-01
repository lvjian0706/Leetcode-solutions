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
    反转从m到n的链表：迭代法
    使用first指针指向位置m，first_pre指向m-1，temp设为null，last指向位置m+1，last_next指向位置n+1；
    使用fist,last以及temp将位置m到n进行反转，接着将first_pre指向反转后的子链表头，反转后的子链表尾指向n+1；
    */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         ListNode* first = head;
         ListNode node(0);
         ListNode* first_pre = &node;
         first_pre->next = head;
         /*
        将first指针指向位置m，first_pre指向位置m-1；
         */
        for(int i=0; i<m-1; i++){
            first = first->next;
            first_pre = first_pre->next;
        }
        ListNode* last = first->next;
        ListNode* temp = NULL;
        /*
        使用fist,last以及temp将位置m到n进行反转,此时temp指向位置m，first指向位置m+1;
        */
        for(int i=m; i<n+1; i++){
            first->next = temp;
            temp = first;
            first = last;
            if(last) last = last->next;
        }
        first_pre->next->next = first;
        first_pre->next = temp;
        return node.next;
    }
};