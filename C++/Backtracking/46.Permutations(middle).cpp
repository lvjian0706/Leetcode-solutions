class Solution {
public:
    /*
    回溯思想：
    1. 当sub_ans中元素个数为nums中的元素个数时，保存；
    2. 循环遍历当前层，将遍历到的元素push进子集中；
    3. 将遍历到的元素添加到set中；
    4. 递归遍历更深层；
    5. 将该数在set中删除；
    6. 将该数去掉后继续遍历当前层；
    */
    void backtrack(vector<int>& nums, vector<int>& sub_ans, vector<vector<int>>& ans, set<int>& Set){
        if(sub_ans.size() == nums.size()){
            ans.push_back(sub_ans);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(Set.find(nums[i])==Set.end()){
                sub_ans.push_back(nums[i]);
                Set.insert(nums[i]);
                backtrack(nums, sub_ans, ans, Set);
                Set.erase(nums[i]);
                sub_ans.pop_back();
            }
        }
    }

    /*
    所有可能的全排列：使用回溯算法，类似树的遍历
    要返回所有全排列，因此应该建立一个二位数组存放答案，其中每个1维数组是各个全排列；
    其中，为了避免全排列中包含相同元素，定义set用来记录已经遍历的元素；
    1. 递归遍历数组，不断计算新全排列并push到答案中；
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub_ans;
        vector<vector<int>> ans;
        set<int> Set;
        backtrack(nums, sub_ans, ans, Set);
        return ans;
    }
};