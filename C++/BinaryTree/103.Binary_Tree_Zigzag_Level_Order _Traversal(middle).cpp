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
    4. 定义flag变量用于判断当前行是从左往右还是从右往左进行遍历；
    5. 循环遍历队头中的元素：
    5.1 使用pnode存储队头元素，保存队头元素的值以及level，并将队头元素出栈；
    5.2 判断队头元素的level与idx是否一致，一致说明队头元素与之前的元素属于相同的level，通过flag的状态判断是将当前元素push到数组末尾还是insert到数组头部；
    5.3. 否则说明队头元素与之前的元素属于不同的level，更新idx，先将subAns插入ans的第一个位置，再清空subAns，并通过flag的状态判断是将当前元素push到数组末尾还是insert到数组头部；；
    5.4 判断是否还有左右孩子，有的话将左右孩子和对应的level（nowIdx+1）存入队列；
    6. 将最后一组subAns的值插入ans的第一个位置，返回ans；
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> subAns;
        queue<pair<TreeNode*, int>> nodeQ;
        nodeQ.push(make_pair(root, 0));
        int idx = 0;
        bool flag = true;
        while(!nodeQ.empty()){
            TreeNode* node = nodeQ.front().first;
            int nowIdx = nodeQ.front().second;
            nodeQ.pop();
            if(nowIdx!=idx){
                ans.push_back(subAns);
                subAns.clear();
                flag = !flag;
                idx = nowIdx;
            }
            if(flag) subAns.push_back(node->val);
            else subAns.insert(subAns.begin(), node->val);
            if(node->left) nodeQ.push(make_pair(node->left, nowIdx+1));
            if(node->right) nodeQ.push(make_pair(node->right, nowIdx+1));
        }
        ans.push_back(subAns);
        return ans;
    }
};