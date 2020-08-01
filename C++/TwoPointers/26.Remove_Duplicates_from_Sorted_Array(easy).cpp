class Solution {
public:
    /*
    删除排序数组中的重复项：数组是排序的，所以重复数据一定是相邻的，使用双指针的思路即可
    1. 定义两个指针，快指针用于找不同元素，慢指针的下一个元素被替换成不同元素即可；
    2. 最后返回慢指针的索引值加一；
    */
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        int left = 0, right = 0;
        int ans;
        while(right<nums.size()){
            if(nums[right]==nums[left]){
                right++;
            }
            else{
                nums[left+1] = nums[right];
                left++;
                right++;
            }
        }
        ans = left+1;
        return ans;
    }
};