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
    层序遍历：宽度优先搜索（bfs）
    1. 创建队列存放二叉树的节点以及节点对应的level，其中使用pair来存放二叉树的节点以及节点对应的level；
    2. 如果树为空，返回空ans数组；
    3. 首先将<root, 0>进栈，并且定义idx为当前level；
    4. 循环遍历队头中的元素：
    4.1 使用pnode存储队头元素，保存队头元素的值以及level，并将队头元素出栈；
    4.2 判断队头元素的level与idx是否一致，一致说明队头元素与之前的元素属于相同的level，直接push进subAns；否则说明队头元素与之前的元素属于不同的level，更新idx，先将subAnspush进ans中，再清空subAns，并将队头元素的值push进去；
    4.3 判断是否还有左右孩子，有的话将左右孩子和对应的level（nowIdx+1）存入队列；
    5. 将最后一组subAns的值push进ans中，返回ans；
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> qnode;
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> subAns;
        qnode.push(make_pair(root, 0));
        int idx = 0;
        while(!qnode.empty()){
            pair<TreeNode*, int> pnode = qnode.front();
            qnode.pop();
            TreeNode* node = pnode.first;
            int nowIdx = pnode.second;
            if(nowIdx ！= idx){
                ans.push_back(subAns);
                subAns.clear();
                idx = nowIdx;
            }
            subAns.push_back(node->val);
            if(node->left) qnode.push(make_pair(node->left, nowIdx+1));
            if(node->right) qnode.push(make_pair(node->right, nowIdx+1));
        }
        ans.push_back(subAns);
        return ans;
    }
};