class Solution {
public:
    /*
    由于时间和空间限制，所以使用二进制的异或运算解答即可；
    */
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};