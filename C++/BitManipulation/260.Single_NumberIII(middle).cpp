class Solution {
public:
    /*
    找出只出现一次的那两个元素：因为是常数空间，考虑位运算：
    x & (-x) ：保留位中最右边1，且将其余的1设为0。 
    1. xy ^= nums[i]：先找到只出现过一次的两个数的异或结果；
    2. dif = xy & (-xy)：找出x与y不同的一位（最右边一位）；
    3. x ^= nums[i]：找到x；
    4. xy^x：找到y；
    */
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xy=0;
        for(int i=0; i<nums.size(); i++){
            xy ^= nums[i];
        }
        int dif = xy & (-xy);
        int x = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&dif){
                x ^= nums[i];
            }
        }
        ans.push_back(x);
        ans.push_back(xy^x);
        return ans;
    }
};