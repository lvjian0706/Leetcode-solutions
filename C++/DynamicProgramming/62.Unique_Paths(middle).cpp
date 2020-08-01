class Solution {
public:
    /*
    动态规划问题：新建dp数组存储到达该点的路径数
    1. 初始状态：由于只能只能向下或者向右移动，dp数组第一列和第一行元素均为1：
    2. 状态方程：dp[i][j] = dp[i-1][j]+dp[i][j-1];
    3. 因为想走到右下角，所以返回答案为dp[m-1][n-1];
    */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        } 
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};