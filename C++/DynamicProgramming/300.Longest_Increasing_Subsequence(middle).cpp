class Solution {
public:
    /*
    要求最长上升子序列的长度：动态规划，dp数组存放最长上升子序列的长度
    1. 初始状态：每个位置上升子序列的长度最少为1（元素本身），因此，dp数组所有元素初始化为1；
    2. 状态方程：求解以每个位置元素为最后一个元素的最长上升子序列的长度，首先判断之前元素中小于该元素的位置，再找到dp数组中这些位置的最大值，dp[i]=max(dp[*])+1；
    3. 返回值：dp数组的最大值；
    */
    int lengthOfLIS(vector<int>& nums) {
        /*
        数组为空时，返回0；
        */
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(), 1);
        int maxLen;
        for(int i=0; i<nums.size(); i++){
            maxLen = dp[i];
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i] && dp[j]+1>maxLen) maxLen=dp[j]+1;
            }
            dp[i] = maxLen;
        }
        int ans = dp[0];
        for(int i=1; i<dp.size(); i++){
            if(dp[i]>ans) ans = dp[i];
        }
        return ans;
    }
};