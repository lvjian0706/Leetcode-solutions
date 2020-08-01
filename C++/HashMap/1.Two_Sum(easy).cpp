class Solution {
public:
    /*
    在该数组中找出和为目标值的那两个整数，并返回他们的数组下标：使用哈希表存放已遍历元素即可；
    1. 定义哈希表用于存放已遍历元素，其中键为该元素，值为元素索引；
    2. 遍历数组，当target-nums[i]在哈希表中不存在时，将该元素存入哈希表中；
    3. 当target-nums[i]存在时，则说明target-nums[i]对应的值（该元素索引）以及当前元素的位置i即为答案；
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            map<int, int>::iterator iter = nums_map.find(target-nums[i]);
            if(iter == nums_map.end()){
                nums_map[nums[i]] = i;
            }
            else{
                ans.push_back(iter->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};