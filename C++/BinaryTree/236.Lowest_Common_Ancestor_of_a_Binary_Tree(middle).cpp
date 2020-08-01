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
    最近公共祖先：可以用深度优先遍历(dfs)
    注意：p、q 为不同节点且均存在于给定的二叉树中；
    1. 如果节点为空，直接返回NULL；
    2. 当遍历到p或q时，直接返回该节点；（找到了其中一个节点）
    3. 递归遍历，如果左子树中遍历到了某一个节点，返回该节点；右子树同理；
    4. 当左子树和右子树都存在某个节点时，返回根节点root；（找到了最近公共节点）
    5. 当只有左子树存在节点时，返回左子树的节点；（有可能只找到了一个节点，也有可能两个节点都在左子树）；右子树同理；
    6. 否则，不存在两个节点，返回null；
    由于是自底向上，而且一定会存在p和q节点，因此在递归过程中最近公共节点会覆盖子节点
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL) return left;
        else if(right!=NULL) return right;
        else return NULL;
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
    递归遍历节点，判断该节点是否是p或q的祖先，同时更新ans：
    1. 如果root不存在，返回false;
    2. 判断左孩子是否为p和q的公共节点以及右孩子是否为p和q的公共节点；
    3. 如果左右孩子同时为p和q的公共节点，或者root是q或者p中的一个且左右孩子中有一个为p和q的公共节点，则说明root为p和q的最近公共节点；
    4. 如果root是q或者p中的一个或者左右孩子中有一个为p和q的公共节点，则说明该节点是p或q的祖先，返回true；
    由于是自底向上判断，且一定存在p和q两个节点，因此找到的一定是最近公共节点；
    */
    bool isAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(!root) return false;
        bool isleft = isAncestor(root->left, p, q, ans);
        bool isright = isAncestor(root->right, p, q, ans);
        if((isleft && isright) || ((root->val==q->val || root->val==p->val) && (isleft || isright))){
            ans = root;
        }
        return isleft || isright || (root->val==q->val || root->val==p->val);
    }

    /*
    最近公共祖先:可以使用深度遍历的方法，使用深度优先搜索（dfs）
    1. 定义变量ans存放最近公共节点
    2. 定义函数isAncestor递归遍历节点，判断该节点是否是p或q的祖先，同时更新ans
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        bool isroot = isAncestor(root, p, q, ans);
        return ans;
    }
};