class Solution {
public:
    /*
    最少跳跃次数：动态规划和贪心算法都可以（贪心比较容易但是思路不好想）
    动态规划：dp数组存放到达该位置的最少跳跃次数；(超出时间限制)
    1. 初始条件：在位置0出发，dp[0]=0；
    2. 状态方程：
    2.1 首先判断从哪些位置可以到达位置n：判断位置n之前的任意一个位置走对应步数是否可以到达位置n，nums[i]>=n-i;
    2.2 查找上述位置中的最小跳跃次数加1即为到位置n的最小跳跃次数：dp[n]=min(dp[*])+1;
    */
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=0;
        int minTimes;
        for(int i=1; i<nums.size(); i++){
            /*
            初始化最小跳跃次数为i，即每次都只跳1步
            */
            minTimes=i;
            for(int j=0; j<i; j++){
                if(nums[j]>=i-j && dp[j]<minTimes) minTimes = dp[j];
            }
            dp[i] = minTimes + 1;
        }
        return dp[nums.size()-1];
    }
};


class Solution {
public:
    /*
    最少跳跃次数：动态规划和贪心算法都可以（贪心比较容易但是思路不好想）
    贪心算法：使用preMax记录目前可以到达的最远位置，使用maxNum记录可以到达的最远位置
    1. preMax和maxNum的初始值设为nums[0],表示第一步能走的最大距离，minJump代表最小跳跃次数，初始化为1；
    2. 循环遍历数组，当i+nums[i]>maxNum时，更新maxNum为i+nums[i]；
    3. 当超过preMax的范围时，更新preMax的值为maxNum，最少跳跃次数加1;
    */
    int jump(vector<int>& nums) {
        /*
        当数组中小于两个元素时，不用跳跃即可到达
        */
        if(nums.size()<2) return 0;
        int preMax=nums[0], maxNum=nums[0];
        int minJump=1;
        for(int i=0; i<nums.size(); i++){
            if(i>preMax){
                minJump++;
                preMax = maxNum;
            }
            if(i+nums[i]>maxNum) maxNum=i+nums[i];
        }
        return minJump;
    }
};

