class Solution {
public:
    /*
    求可行个数：动态规划
    1. 初始条件：爬到0层有1种方法，爬到1层有1种方法（爬1阶），dp[0]=1，dp[1]=1,;
    2. 状态方程：爬到第n层可以在n-1层爬1阶，也可以在n-2层爬2阶，因此dp[n]=dp[n-1]+dp[n-2];
    */
    int climbStairs(int n) {
        if(n==0) return 1;
       vector<int> dp(n+1);
       dp[0] = 1, dp[1] = 1;
       for(int i=2;i<n+1;i++){
           dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
    }
};