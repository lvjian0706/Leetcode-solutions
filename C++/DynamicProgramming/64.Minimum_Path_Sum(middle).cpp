class Solution {
public:
    /*
    动态规划问题：新建dp数组存储路径上的最小数字和
    1. 初始状态：由于只能只能向下或者向右移动，dp数组第一列和第一行元素计算方式：
    1.1 dp数组第一列的元素计算方式为dp[i][0] = dp[i-1][0] + grid[i][0];
    1.2 dp数组第一行的元素计算方式为dp[0][i] = dp[0][i-1] + grid[0][i];
    2. 状态方程：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    3. 因为想走到右下角，所以返回答案为dp[m-1][n-1];
    */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};