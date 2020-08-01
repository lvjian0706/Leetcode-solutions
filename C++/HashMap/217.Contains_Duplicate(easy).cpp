class Solution {
public:
    /*
    给定一个整数数组，判断是否存在重复元素。
    方法1： 排序后判断前后元素是否相同，略；
    方法2： 使用Set或者哈希表保存不同元素，在保存过程中，判断当前元素是否已经在Set或者哈希表中出现过，如果有，则存在重复元素；
    */
    bool containsDuplicate(vector<int>& nums) {
        set<int> no_duplicate;
        for(int i=0; i<nums.size(); i++){
            if(no_duplicate.find(nums[i]) == no_duplicate.end()){
                no_duplicate.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};