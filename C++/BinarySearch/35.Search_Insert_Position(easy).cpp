class Solution {
public:
    /*
    有序数组查找目标值：二分查找
    1. nums[mid]==target时，返回索引值
    2. nums[mid]>target时，需要根据nums[mid-1]的值与target的比较结果进行判定：
    2.1 nums[mid-1]>=target时，目标值在mid左侧，right更新为mid-1；
    2.2 nums[mid-1]<target时，目标值应该插入在mid-1和mid中间，返回mid；
    2.3 考虑越界情况，mid==0时，目标值小于数组第一个元素，应该插入到nums[0]处；
    3. nums[mid]<target时，需要根据nums[mid+1]的值与target的比较结果进行判定：
    3.1 nums[mid+1]>target时，目标值应该插入在mid-1和mid中间，返回mid+1；
    3.2 nums[mid+1]<=target时，目标值在mid右侧，left更新为mid+1；
    3.3 考虑越界情况，mid==nums.size()-1时，目标值大于数组最后一个元素，应该插入到nums[nums.size()]处；
    */
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                if(mid==0 || nums[mid-1]<target) return mid;
                else if(nums[mid-1]>=target) right = mid - 1;
            }
            else if(nums[mid]<target){
                if(mid==nums.size()-1 || nums[mid+1]>target) return mid+1;
                else if(nums[mid+1]<=target) left = mid + 1;  
            }
        }
        return -1;
    }
};