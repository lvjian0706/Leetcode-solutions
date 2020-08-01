class Solution {
public:
    /*
    使用 O(1) 的额外空间反转字符串，可以使用双指针，额外空间用于元素交换
    */
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};