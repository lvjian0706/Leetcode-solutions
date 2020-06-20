class Solution {
public:
    /*
    有序数组查找目标值：二分查找
    1. 需要将nums[mid]与nums[left]进行比较，判断旋转区间
    2. 根据旋转区间范围以及target与nums[mid]的比较共同查找目标值
    */
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target) return mid;
            /*
            只有一个元素且不等于target时，返回-1；
            */
            else if(left==right){
                return -1;
            }
            /*
            nums[mid]大于nums[left]时，数组最小值在nums[mid]右边：
            1. nums[mid]大于target时，需要根据target与nums[left]大小判断target所在区间
            1.1 target大于nums[left]时，target位于nums[left:mid-1]
            1.2 target小于nums[left]时，target位于nums[mid+1：]
            2. nums[mid]小于target时，target位于nums[mid+1：]
            */
            if(nums[mid]>nums[left]){
                if(nums[mid]>target){
                    if(target>nums[left]) right = mid-1;
                    else if(target<nums[left]) left = mid+1;
                    else return left;
                }
                else if(nums[mid]<target){
                    left = mid+1;
                }
            }
            /*
            nums[mid]小于nums[left]时，数组最小值在nums[mid]左边：
            1. nums[mid]小于target时，需要根据target与nums[left]大小判断target所在区间
            1.1 target大于nums[left]时，target位于nums[left:mid-1]
            1.2 target小于nums[left]时，target位于nums[mid+1：]
            2. nums[mid]大于target时，target位于nums[left:mid-1]
            */
            else if(nums[mid]<nums[left]){
                if(nums[mid]<target){
                    if(target>nums[left]) right = mid-1;
                    else if(target<nums[left]) left = mid+1;
                    else return left;
                }
                else if(nums[mid]>target){
                    right = mid-1;
                }
            }
            /*
            nums[mid]等于nums[0]时，数组只有两个元素：
            1. nums[mid]不等于target并且nums[mid+1]不等于target时时，没有目标值
            2. 否则返回索引值；
            */
            else{
                if(nums[mid]!=target){
                    if(nums[mid+1]==target) return mid+1;
                    else return -1;
                }
                else return mid;
            }
        }
        /*
        如果没有找到，返回-1；
        */
        return -1;
    }
};