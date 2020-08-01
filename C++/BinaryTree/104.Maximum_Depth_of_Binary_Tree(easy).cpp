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
    深度优先搜索：
    1. 传入参数：当前节点以及上一层节点的深度；
    2. 如果当前节点为空，返回上一层节点的深度；
    3. 否则，采用分治思想，递归计算左子树的深度和右子树的深度，返回深度最大值；
    */
    int dfs(TreeNode* root, int depth){
        if(!root) return depth;
        int leftDepth = dfs(root->left, depth+1);
        int rightDepth = dfs(root->right, depth+1);
        return max(leftDepth, rightDepth);
    }

    /*
    树的遍历：求树的最长路径的深度，可以使用深度优先搜索（dfs）
    */
    int maxDepth(TreeNode* root) {
        int ans = dfs(root, 0);
        return ans;
    }
};