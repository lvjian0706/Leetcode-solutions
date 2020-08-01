class Solution {
public:
    /*
    是否能够到达：动态规划和贪心算法都可以（贪心比较容易但是思路不好想）
    动态规划：dp数组存放能否到达该位置，0：不可以1：可以；
    1. 初始条件：在位置0出发，所以一定可以到达位置0，dp[0]=1；
    2. 状态方程：判断是否可以到达位置n之前的任意一个位置，且在该位置走对应步数可以到达位置n，如果存在则可以到达该位置，dp[n]=dp[i]&&nums[i]>=n-i;
    */
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j]&&nums[j]>=i-j){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

class Solution {
public:
    /*
    是否能够到达：动态规划和贪心算法都可以（贪心比较容易但是思路不好想）
    贪心算法：使用maxNum记录当前可以到达的最远位置
    1. maxNum<i时，代表当前可以到达的最远位置比i小，因此无法到达i，返回false
    2. (i+nums[i])>maxNums时，代表在位置i可以到达比maxNums更远的位置，更新maxNums
    */
    bool canJump(vector<int>& nums) {
        int maxNums = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxNums<i) return false;
            if((i+nums[i])>maxNums) maxNums = i+nums[i];
        }
        return true;
    }
};