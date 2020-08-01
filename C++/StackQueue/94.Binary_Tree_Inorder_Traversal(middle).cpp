/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    /*
    回溯方法
    */
    void DFS(TreeNode* root, vector<int> &ans){
        if(!root) return;
        DFS(root->left, ans);
        ans.push_back(root->val);
        DFS(root->right, ans);
    }

    /*
    中序遍历，可以使用回溯思想
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        DFS(root, ans);
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    迭代方法：（使用vector和stack共同解决）
    1. 中序遍历，访问左孩子节点存到栈中；
    2. 访问结束后，pop()出栈顶元素，存到结果数组中；
    3. 将root定义为栈顶元素的右孩子，遍历右子树；
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> inorder_tree;
        while(root || !inorder_tree.empty()){
            while(root){
                inorder_tree.push(root);
                root = root->left;
            }
            TreeNode* temp = inorder_tree.top();
            inorder_tree.pop();
            ans.push_back(temp->val);
            root = temp->right;
        }
        return ans;
    }
};