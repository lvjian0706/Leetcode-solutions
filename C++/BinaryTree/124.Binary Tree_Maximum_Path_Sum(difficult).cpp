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
    计算每个节点的贡献值，同时使用全局变量maxSum记录遍历到当前节点时的最大路径和：
    1. 当该节点为空时，贡献值为0；
    2. 计算该节点左子树和右子树的贡献值，其中，需要保证贡献值大于等于0（贡献值为负数时，不将该子树的路径和加入到最终的结果中，因此，相当于加0）；
    3. 计算该节点的最大路径和，更新maxSum；
    4. 返回该节点的贡献值（该节点的值加max（左子树的最大路径和，右子树的最大路径和））；
    */
    int nodeGain(TreeNode* root, int &maxSum){
        if(!root) return 0;
        int leftSum = max(nodeGain(root->left, maxSum), 0);
        int rightSum = max(nodeGain(root->right, maxSum), 0);
        int nowSum = root->val + leftSum + rightSum;
        maxSum = max(maxSum, nowSum);
        return root->val + max(leftSum, rightSum);
    }
    /*
    最大路径和：需要进行深度遍历，使用深度优先搜索（dfs）
    1. 定义maxSum变量实时保存每个节点的最大路径和；
    2. 计算每个节点的贡献值，同时使用全局变量maxSum记录遍历到当前节点时的最大路径和：
    3. 返回maxSum；
    */
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int rootPathSum = nodeGain(root, maxSum);
        return maxSum;
    }
};