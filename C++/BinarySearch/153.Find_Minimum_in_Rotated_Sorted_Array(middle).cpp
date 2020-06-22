class Solution {
public:
    /*
    查找旋转数组中最小值：由于原始数组是升序数组，所以使用二分查找，找原始数组中起始点
    原始数组最小点应该小于左右两侧元素，具体的最小点应该小于左侧元素
    1. 当nums[0]<nums[nums.size()-1]时，原数组没有旋转，返回nums[0];
    2. mid==0时, nums[mid]>nums[mid+1]，第一个元素为最大值，返回nums[1];
    3. nums[mid]<nums[mid-1]，则找到最小点，返回nums[mid];
    4. nums[mid]>nums[mid-1]，需要判断当前点在最小点左边还是右边，可以结合与nums[0]的关系进行判断：
    nums[mid]>nums[0]，由于数组旋转过，所以最小点左边是升序数组，且最小值右边恒小于左边，因此当前元素位于最小点左边，left=mid+1;否则，right=mid-1;
    */
    int findMin(vector<int>& nums) {
        /*
        只有一个元素时，返回该元素
        */
        if(nums.size()==1) return nums[0];
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[0]<nums[nums.size()-1]) return nums[0];
            else if(mid==0 && nums[mid]>nums[mid+1]) return nums[1];
            else if(nums[mid] < nums[mid-1]) return nums[mid];
            else if(nums[mid] > nums[mid-1]){
                if(nums[mid] > nums[0]) left = mid + 1;
                else if(nums[mid] < nums[0]) right = mid - 1;
            }
        }
        return -1;
    }
};