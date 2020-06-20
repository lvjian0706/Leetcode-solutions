class Solution {
public:
    
    /*
    查找数组中元素的起始位置即左端点
    1. 当nums[mid]==target时，需要根据nums[mid-1]判断是否为左端点
    1.1 nums[mid-1]<target，是左端点，返回索引值
    1.2 mid==0， 位于数组边界，是左端点，返回0
    1.3 nums[mid-1]==target， 不是左端点，将right更新为mid-1继续判断
    2. 当nums[mid]不等于target时，缩小搜索区间继续查找
    */
    int searchLeft(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        while(right>=left){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                if(mid==0 || nums[mid-1]<target) return mid;
                else if(nums[mid-1]==target) right = mid - 1;
            }
            else if(nums[mid]>target) right = mid - 1;
            else if(nums[mid]<target) left = mid + 1;
        }
        /*
        没有找到target时，返回-1；
        */
        return -1;
    }
    
    /*
    查找数组中元素的起始位置即左端点
    1. 当nums[mid]==target时，需要根据nums[mid+1]判断是否为右端点
    1.1 nums[mid+1]>target，是右端点，返回索引值
    1.2 mid==nums.size()-1， 位于数组边界，是右端点，返回len(nums-1)
    1.3 nums[mid-1]==target， 不是左端点，将left更新为mid+1继续判断
    2. 当nums[mid]不等于target时，缩小搜索区间继续查找
    */
    int searchRight(vector<int>& nums, int target){
        int left=0, right=nums.size()-1;
        while(right>=left){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                if(mid==nums.size()-1 || nums[mid+1]>target) return mid;
                else if(nums[mid+1]==target) left = mid + 1;
            }
            else if(nums[mid]>target) right = mid - 1;
            else if(nums[mid]<target) left = mid + 1;
        }
        /*
        没有找到target时，返回-1；
        */
        return -1;
    }

    /*
    有序数组查找元素：二分查找
    数组中存在重复数字，因此需要对要查找元素的左端点和右端点进行分别处理；
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};