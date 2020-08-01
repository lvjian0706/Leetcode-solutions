class Solution {
public:
    /*
    回溯思想：
    1. 结束条件是遍历到了数组末尾；
    2. 每遍历到一个数，push进子集，并将子集push到答案中；
    3. 继续递归遍历；
    4. 将该数去掉后继续遍历；
    */
    void backtrack(vector<int>& nums, int i, vector<int>& sub_ans, vector<vector<int>>& ans){
        if(i>nums.size()-1) return;
        sub_ans.push_back(nums[i]);
        ans.push_back(sub_ans);
        backtrack(nums, i+1, sub_ans, ans);
        sub_ans.pop_back();
        backtrack(nums, i+1, sub_ans, ans);
    }

    /*
    穷尽所有可能：使用回溯算法，类似树的遍历
    要返回所有子集，因此应该建立一个二位数组存放答案，其中每个1维数组是各个子集；
    1. 先保存空子集；
    2. 递归遍历数组，不断计算新子集并push到答案中；
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        ans.push_back(sub_ans);
        backtrack(nums, 0, sub_ans, ans);
        return ans;
    }
};

方法2：
class Solution {
public:
    /*
    回溯思想：
    1. 保存子集；
    2. 结束条件是遍历到了数组末尾；
    3. 循环遍历当前层，将遍历到的元素push进子集中；
    4. 递归遍历更深层；
    5. 将该数去掉后继续遍历当前层；
    */
    void backtrack(vector<int>& nums, int i, vector<int>& sub_ans, vector<vector<int>>& ans){
        ans.push_back(sub_ans);
        if(i==nums.size()) return;
        for(int j=i; j<nums.size(); j++){
            sub_ans.push_back(nums[j]);
            backtrack(nums, j+1, sub_ans, ans);
            sub_ans.pop_back();
        }
    }

    /*
    穷尽所有可能：使用回溯算法，类似树的遍历
    要返回所有子集，因此应该建立一个二位数组存放答案，其中每个1维数组是各个子集；
    1. 递归遍历数组，不断计算新子集并push到答案中；
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub_ans;
        vector<vector<int>> ans;
        backtrack(nums, 0, sub_ans, ans);
        return ans;
    }
};