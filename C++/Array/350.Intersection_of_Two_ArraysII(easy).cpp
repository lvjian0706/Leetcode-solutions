class Solution {
public:
    /*
    计算两个数组的交集:
    方法1. 先排序，后使用双指针遍历
    1. 将两个数组排序，从小到大即可；
    2. 定义两个指针用于遍历两个数组；
    3. 当两个元素相等时，存入答案中，nums1[i]<nums2[j]时，i++，找比nums1[i]大的元素继续判断，当nums1[i]>nums2[j]时，j++，找比nums2[j]大的元素继续判断；
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
        }
        return ans;
    }
};


class Solution {
public:
    /*
    计算两个数组的交集:
    方法2. 使用哈希表存放nums1中的元素以及出现次数，然后遍历nums2并将重复元素放入答案中，遍历过程中，碰到重复元素需要将哈希表中的出现次数减1；
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums1_map;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            if(nums1_map.find(nums1[i]) == nums1_map.end()){
                nums1_map[nums1[i]] = 1;
            }
            else nums1_map[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++){
            if(nums1_map.find(nums2[j]) != nums1_map.end() && nums1_map[nums2[j]] > 0){
                ans.push_back(nums2[j]);
                nums1_map[nums2[j]]--;
            }
        }
        return ans;
    }
};