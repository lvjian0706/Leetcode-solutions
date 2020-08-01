/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
    复制带随机指针的链表：深拷贝
    1. 循环遍历链表，一边遍历一边新建节点，将新节点赋值为与该节点一样的值，然后插入到该节点后边；
    2. 再次循环遍历新链表，步长为2，一边遍历一边将后边的节点（1中新建的节点）的random赋值为与前边节点（原始节点）一致；
    3. 将新链表拆分
    */
    Node* copyRandomList(Node* head) {
        Node* insert_head = head;
        while(insert_head){
            Node* temp_node = new Node(insert_head->val);
            temp_node->next = insert_head->next;
            insert_head->next = temp_node;
            insert_head = insert_head->next->next;
        }
        Node* random_head = head;
        while(random_head && random_head->next){
            if(random_head->random) random_head->next->random = random_head->random->next;
            else random_head->next->random = NULL;
            random_head = random_head->next->next;
        }
        Node node(0);
        Node* copy_head = &node;
        Node* new_head = head;
        while(new_head && new_head->next){
            copy_head->next = new_head->next;
            new_head->next = new_head->next->next;
            new_head = new_head->next;
            copy_head = copy_head->next;
        }
        copy_head->next = NULL;
        return node.next;
    }
};