class Solution {
public:
        /*
        寻找两个数组第k小的元素
        1. 当nums1为空时，返回nums2中第k小的元素；当nums2为空时，返回nums1中第k小的元素；
        2. 当k==1时，nums1[0]和nums2[0]中的最小值为返回值；
        3.1 如果nums1[k/2-1]<nums2[k/2-1]，说明nums1[0:k/2-1]中不可能存在中位数， 更新nums1=nums1[k/2:]； 同时更新k-=2/k；反之亦然；
        3.2 如果当前nums1的长度小于k/2-1，则将3.1中nums1[k/2-1]替换为nums[len1-1]，保证数组不越界，更新nums1=nums1[len:](空数组)，同时更新k-=此时nums1的长度;
        */
    double findKth(vector<int>& nums1, vector<int>& nums2, int len1, int len2, int k){
        int left1 = 0, left2 = 0;
        while(true){
            if(left1==len1){
                return nums2[left2+k-1];
            }
            if(left2==len2){
                return nums1[left1+k-1];
            }
            if(k==1){
                return min(nums1[left1], nums2[left2]);
            }
            /*
            定义new_left检查是否越界
            */
            int new_left1 = min(left1+k/2-1, len1-1);
            int new_left2 = min(left2+k/2-1, len2-1);
            /*
            更新k的值，以及使用left来更新数组
            */
            if(nums1[new_left1] <= nums2[new_left2]){
                k -= new_left1 - left1 + 1;
                left1 = new_left1 + 1;
            }
            else{
                k -= new_left2 - left2 + 1;
                left2 = new_left2 + 1;
            }
        }
    }
        /*
        寻找两个正序数组的中位数，即找到两个数组合并后第(nums1.size()+nums2.size())/2小的元素
        */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        k = (nums1.size()+nums2.size())/2;
        当nums1.size()+nums2.size()为奇数时，返回第k+1小的元素；
        当nums1.size()+nums2.size()为偶数时，返回第k小的元素和第k+1小的元素均值；
        */
        int len1 = nums1.size();
        int len2 = nums2.size();
        int k = (len1+len2)/2;
        if((len1+len2)%2==0) return (findKth(nums1, nums2, len1, len2, k) + findKth(nums1, nums2, len1, len2, k+1)) / 2;
        else return findKth(nums1, nums2, len1, len2, k+1);
    }
};