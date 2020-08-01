class Solution {
public:
    /*
    将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序：快慢指针
    1. 定义快指针与慢指针，指向第一个不为0的元素；
    2. 快指针移动，当碰到不为0的元素时，覆盖掉慢指针的位置，同时快慢指针同时向前移动；
    3. 最后，将慢指针后的位置全部设为0；
    */
    void moveZeroes(vector<int>& nums) {
        int slow=0, fast=0;
        while(slow<nums.size() && nums[slow]!=0){
            slow++;
            fast++;
        }
        while(fast<nums.size()){
            if(nums[fast]!=0){
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
            else{
                fast++;
            }
        }
        for(int i=slow; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};