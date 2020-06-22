// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    /*
    由于错误版本之后的所有版本都是错的，因此，需要找到第一个isBadVersion(mid)==false的版本：
    1. isBadVersion(mid)==true，说明当前版本或当前版本之前的版本出现错误，需要根据上一个版本的情况进行判断
    1.1 isBadVersion(mid-1)==true，说明当前版本之前的版本出现错误，right=mid-1;
    1.2 isBadVersion(mid-1)==false，说明当前版本之前的版本都是正确的，当前版本为第一个出错的版本，返回mid；
    1.3 mid==1时，为边界情况，说明从第一个版本就出错了；
    2. isBadVersion(mid)==false，说明当前版本没有问题，left=mid+1；
    */
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)==false) left = mid + 1;
            else if(isBadVersion(mid)==true){
                if(mid==1 || isBadVersion(mid-1)==false) return mid;
                else if(isBadVersion(mid-1)==true) right = mid - 1;
            }
        }
        return 0;
    }
};