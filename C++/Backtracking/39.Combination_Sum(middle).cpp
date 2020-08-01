class Solution {
public:
    /*
    1. 当当前组合的和大于target时，直接return，等于target时，将组合push到最终答案中；
    2. 为了避免重复组合的情况，定义变量i用于记录当前遍历到了哪个元素，之前的元素不再重复遍历；
    3. 从第i个元素开始遍历，套用回溯算法模板，将当前元素push到组合中，sum加上当前元素，继续递归；
    4. 在组合中删除当前元素，sum减去当前元素后遍历i+1个元素；
    */
    void backtrack(vector<int>& candidates, int target, int i, int& sum, vector<vector<int>>& ans, vector<int>& sub_ans){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(sub_ans);
            return;
        }
        for(int j=i; j<candidates.size(); j++){
            sub_ans.push_back(candidates[j]);
            sum += candidates[j];
            backtrack(candidates, target, j, sum, ans, sub_ans);
            sub_ans.pop_back();
            sum -= candidates[j];
        }
    }

    /*
    统计所有可能的排列情况：回溯算法
    1. 新建一维数组存储每个组合，新建二维数组存储最终结果；
    2. 找出 candidates 中所有可以使数字和为 target 的组合，所以定义sum变量用于存储当前组合的和；
    3. 递归遍历数组，不断计算符合条件的组合并push到答案中；
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        int sum = 0;
        backtrack(candidates, target, 0, sum, ans, sub_ans);
        return ans;
    }
};