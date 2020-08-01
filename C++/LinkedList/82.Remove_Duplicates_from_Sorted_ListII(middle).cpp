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
    删除重复节点，只保留没有重复出现的数字:
    1. 为了避免头节点重复需要删除，新建一个头节点指向原来的头节点，最后返回新建节点的next；
    2. 定义last和fast节点用来遍历链表，并找出重复节点：
    2.1 last和fast初始化为head节点，循环判断last和fast的next是否相等，如果相等，fast前进一位；
    2.2 如果fast发生了变化，也就是last和fast不是同一个节点时，说明从last到fast之间是重复元素，new_head的next指向fast的下一个元素；
    2.3 如果last和fast是同一个节点时，说明该元素不是重复元素，new_head前进到该元素；
    2.4 last和fast前进一位，保证永远在new_head前面一位；
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode node(0);
        ListNode* new_head = &node;
        new_head->next = head;
        ListNode* last = head;
        ListNode* fast = head;
        while(fast && fast->next){
            while(fast->next && last->val == fast->next->val){
                fast = fast->next;
            }
            if(last==fast){
                new_head = last;
            }
            else{
                new_head->next = fast->next;
            }
            last = new_head->next;
            fast = new_head->next;
        }
        return node.next;
    }
};