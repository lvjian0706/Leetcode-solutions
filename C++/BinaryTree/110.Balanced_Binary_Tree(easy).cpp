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
    计算二叉树的深度：
    1. 如果不存在该节点，返回0；
    2. 计算左子树深度和右子树深度；
    3. 该树的深度为左子树深度和右子树深度的最大值加1（1代表根节点深度）；
    */
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right)+1;
    }

    /*
    判断二叉树是否平衡：考虑到需要判断二叉树中每个节点并计算深度，可以使用深度优先搜索（dfs）
    1. 如果不存在节点，返回true；
    2. 判断左子树和右子树是否是平衡二叉树；
    3. 计算左子树深度和右子树深度；
    4. 当左子树和右子树都是平衡二叉树，且左子树深度和右子树深度差的绝对值不超过1时，返回true，否则，返回false；
    */
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool leftBanlanced = isBalanced(root->left);
        bool rightBanlanced = isBalanced(root->right);
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(leftBanlanced && rightBanlanced && lheight <= rheight+1 && rheight <= lheight+1){
            return true;
        }
        else return false;
    }
};