class Solution {
public:
    /*
    动态规划问题：新建dp数组存储到达该点的路径数
    1. 初始状态：由于只能只能向下或者向右移动，dp数组第一列和第一行元素均为1，
    （其中，考虑到如果有障碍，从该点往后的所有点都无法到达，因此，定义flag变量，碰到障碍则flag=1，dp数组从该点开始全都赋0）
    2. 状态方程：dp[i][j] = dp[i-1][j]+dp[i][j-1];
    （其中，考虑到如果有障碍，到障碍点的路径数应该设置为0，表明该点不通且无法到达）
    3. 因为想走到右下角，所以返回答案为dp[m-1][n-1];
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int flag = 0;
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==1){
                flag = 1;
            }
            if(!flag) dp[i][0] = 1;
            else dp[i][0] = 0;
        }
        flag = 0;
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i]==1){
                flag = 1;
            }
            if(!flag) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};