class Solution {
public:
    /*
    最少的组合个数：动态规划问题，dp数组中存放凑成金额i所需要的最少硬币个数
    1. 初始状态：初始状态时，默认除了0之外所有面额都不能凑成，都赋值为-1，面额为0时，可使用0枚硬币凑成，因此，dp[0]=0；
    2. 状态方程：面额i可以根据dp[i-coins[j]]的最小值加1凑成，因此，dp[i]]=min(dp[i-coins[j]])+1；(其中，需要判断边界值i>=coins[j]以及dp[i-coins[j]]!=-1即面额i是否可以用coins中的硬币凑成)
    3. 返回值：dp[amount]
    */
    int coinChange(vector<int>& coins, int amount) {
        /*
        如果没有硬币，返回-1；
        */
        if(coins.size()==0) return -1;
        vector<int> dp(amount+1, -1);
        dp[0] =  0;
        for(int i=1; i<amount+1; i++){
            for(int j=0; j<coins.size(); j++){
                if(i>=coins[j] && dp[i-coins[j]]!=-1){
                    if(dp[i]==-1) dp[i] =  dp[i-coins[j]] + 1;
                    else dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount];
    }
};