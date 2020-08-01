class Solution {
public:
    /*
    旋转升序数组中查找目标值：二分查找；遇到重复元素数组，可以在循环过程中先去掉两端重复元素，方便判断
    1. 当数组为空时，返回false;
    2. 为了方便判断，循环过程中先将两端的重复元素去掉
    2.1 当nums[left]==nums[left+1]时，left++;
    2.2 当nums[right]==nums[right--]时，right--;
    3. 当只有一个元素时，比较是否一致即可；
    4. nums[mid]==target，返回true；
    5. nums[mid]<target时，结合nums[mid],target,nums[left]三者关系共同判断：
    5.1 nums[mid]>nums[left]，说明从左到右依次为nums[left]，nums[mid]，target，left=mid+1;
    5.2 nums[mid]<nums[left]时：
    5.2.1 target>nums[left]时， 说明从左到右依次为nums[left],target，nums[mid]，right=mid-1;
    5.2.2 target<nums[left]时， 说明从左到右依次为nums[left]，nums[mid]，target，left=mid+1;
    5.2.3 target==nums[left]，返回true;
    5.3 nums[mid]==nums[left]，说明只有两个元素，比较nums[mid+1]与target是否一致即可；
    6. nums[mid]>target时，结合nums[mid],target,nums[left]三者关系共同判断：
    6.1 nums[mid]<nums[left]，说明从左到右依次为nums[left]，target，nums[mid]，right=mid-1;
    6.2 nums[mid]>nums[left]时：
    6.2.1 target>nums[left]时， 说明从左到右依次为nums[left],target，nums[mid]，right=mid-1;
    6.2.2 target<nums[left]时， 说明从左到右依次为nums[left]，nums[mid],target，left=mid+1;
    6.2.3 target==nums[left]，返回true;
    6.3 nums[mid]==nums[left]，说明只有两个元素，比较nums[mid+1]与target是否一致即可；
    */
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        int left=0, right=nums.size()-1;
        while(left<=right){
            while(left+1<=right && nums[left]==nums[left+1]) left++;
            while(right-1>=left && nums[right]==nums[right-1]) right--;
            if(left==right) return nums[left]==target;
            int mid = left + (right - left) / 2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target){
                if(nums[mid]==nums[left]) return nums[mid+1]==target;
                else if(nums[mid]>nums[left]) left = mid + 1;
                else if(nums[mid]<nums[left]){
                    if(target>nums[left]) right=mid-1;
                    else if(target<nums[left]) left=mid+1;
                    else if(target==nums[left]) return true; 
                }
            }
            else if(nums[mid]>target){
                if(nums[mid]==nums[left]) return nums[mid+1]==target;
                else if(nums[mid]<nums[left]) right=mid-1;
                else if(nums[mid]>nums[left]){
                    if(target>nums[left]) right=mid-1;
                    else if(target<nums[left]) left=mid+1;
                    else if(target==nums[left]) return true; 
                }
            }
        }
        return false;
    }
};