class Solution {
public:
    /*
    对于0≤i≤num范围中的每个数字i，计算其二进制数中的1的数目并将它们作为数组返回：动态规划问题
    1. 奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
    2. 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
    */
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        for(int i=1; i<num+1; i++){
            if(i%2==0){
                dp[i] = dp[i/2];
            }
            else{
                dp[i] = dp[i-1] + 1;
            }
        }
        return dp;
    }
};