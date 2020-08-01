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
    新建头节点，进行归并排序；
    */
    ListNode* mergeSort(ListNode* left, ListNode* right){
        ListNode node(0);
        ListNode* new_head = &node;
        while(left && right){
            if(left->val<right->val){
                new_head->next = left;
                left =  left->next;
            }
            else{
                new_head->next = right;
                right = right->next;
            }
            new_head = new_head->next;
        }
        while(left){
            new_head->next = left;
            left =  left->next;
            new_head = new_head->next;
        }
        while(right){
            new_head->next = right;
            right =  right->next;
            new_head = new_head->next;
        }
        return node.next;
    }

    /*
    链表排序：
    O(nlogn) 时间复杂度以及常数级空间复杂度，考虑归并排序
    使用快慢指针找链表的中点，将链表分为前半部分和后半部分，递归的对前半部分以及后半部分进行排序，最后对两部分进行总的排序
    其中，在分割时，需要将前半部分的尾指针next赋为null，将链表切断，否则会无限递归；后半部分的起始点则为slow->next；
    */
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* half = slow->next;
        slow->next = NULL;
        return mergeSort(sortList(head), sortList(half));
    }
};