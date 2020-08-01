class Solution {
public:
    /*
    动态规划问题，建立dp数组；
    由于是三角形，求自顶向下的最小路径和，为了计算方便，适合从下向上计算，最后dp[0][0]即为最终答案；
    1. 初始状态：dp数组的每一个值代表从下向上的最小路径和，其中，dp数组最后一行为原始三角形中最下一行元素；
    2. 状态方程：dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        三角形最后一行索引以及三角形最后一行长度
        */
        int lastRaw = triangle.size(), maxLen = triangle[triangle.size()-1].size();
        vector<vector<int>> dp(lastRaw, vector<int>(maxLen));
        for(int i=0; i<maxLen; i++){
            dp[lastRaw-1][i] = triangle[lastRaw-1][i];
        }
        /*
        从倒数第二行开始往上计算，每行的数组元素个数比下边一行少1；
        */
        for(int i=lastRaw-2; i>=0; i--){
            maxLen--;
            for(int j=0; j<maxLen; j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};