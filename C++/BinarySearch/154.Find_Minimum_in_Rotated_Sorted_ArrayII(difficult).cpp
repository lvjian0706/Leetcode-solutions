class Solution {
public:
    /*
    寻找旋转的升序数组最小值：二分查找，数组中的最小值恒小于左右两侧的第一个不同元素；
    在本题中，适合使用nums[mid]与nums[right]的值进行判断；且需要将数组两端重复元素去重；
    1. nums中没有元素返回-1；nums中只有一个元素，直接返回；
    2. 如果nums[0]<nums[nums.size()-1]，说明数组仍然是升序，返回nums[0];
    3. 为了简化判断，每次循环过程中，将数组两端的重复元素去除：
    3.1 当nums[left]==nums[left+1]时，left++;
    3.2 当nums[right]==nums[right--]时，right--;
    4. 如果去重后只有一个元素，直接返回
    5. nums[mid]<nums[right]，需要结合nums[mid]与nums[mid-1]的结果共同判断
    5.1 nums[mid]>=nums[mid-1]，还在升序区间，且最小值在nums[mid]左侧，right=mid-1;
    5.2 nums[mid]<nums[mid-1]，为最小值，返回nums[mid];
    6. nums[mid]>nums[right]，最小值在nums[mid]右侧，left=mid+1;
    */
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        int left=0, right=nums.size()-1;
        while(left<=right){
            while(left+1<=right && nums[left]==nums[left+1]){
                left++;
            }
            while(right-1>=left && nums[right]==nums[right-1]){
                right--;
            }
            if(left==right) return nums[left];
            int mid = left + (right - left) / 2;
            if(nums[mid]<nums[right]){
                if(nums[mid]>=nums[mid-1]) right = mid - 1;
                else if(nums[mid]<nums[mid-1]) return nums[mid];
            }
            else if(nums[mid]>nums[right]) left = mid + 1;
        }
        return -1;
    }
};

