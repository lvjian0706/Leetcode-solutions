class Solution {
public:
    /*
    最长公共子序列的长度：动态规划问题，dp数组存放text1[0:i]与text2[0:j]的最长公共子序列的长度（二维数组）
    1. 初始状态：当text1[0:i]中有元素与text2[0]相等时，dp[i][0]=1；当text2[0:j]中有元素与text1[0]相等时，dp[0][j]=1；
    2. 状态方程：
    2.1 当text1[i]==text2[j]时，dp[i][j] = dp[i-1][j-1]+1;
    2.2 否则，dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    3. 返回值：dp[text1.size()-1][text2.size()-1]
    */
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        vector<vector<int>> dp(m, vector<int>(n));
        int flag = 0;
        for(int i=0; i<m; i++){
            if(text1[i]==text2[0]) flag=1;
            if(flag) dp[i][0]=1;
            else dp[i][0]=0;
        }
        flag = 0;
        for(int j=0; j<n; j++){
            if(text2[j]==text1[0]) flag=1;
            if(flag) dp[0][j]=1;
            else dp[0][j]=0;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(text1[i]==text2[j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};