class Solution {
public:
    /*
    找出不含有重复字符的最长子串的长度.
    最长子串思路：使用滑动窗口遍历字符串，当碰到新元素时将其append到当前子串中，同时记录此时的子串长度，并及时更新最长的字串长度；当碰到的元素不是新元素（已经在子串中出现过）时，子串左端开始收缩，直到将与新碰到的元素一样的元素被剔除出子串为止；
    1. 定义map用来记录元素出现个数，定义两个int值用来记录当前子串长度以及最长子串长度；
    2. 当当前元素在子串中出现过时，说明当前元素在子串中重复，因此将左边界收缩，直到碰到右边界或当前元素在子串中不重复，子串的长度随着左边界收缩即使更新；
    3. 此时当前元素在子串中一定不重复，因此将其append到当前子串中，同时记录此时的字串长度，并及时更新最长的字串长度；
    */
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        map<char, int> num_char;
        int now_ans = 0;
        int max_ans = 0;
        int left = 0;
        for(int i=0; i<s.length(); i++){
            if(num_char.find(s[i])==num_char.end()){
                num_char[s[i]] = 0;
            }
        }
        for(int i=0; i<s.length(); i++){
            while(num_char[s[i]]==1){
                num_char[s[left]]--;
                left++;
                now_ans--;
            }
            num_char[s[i]]++;
            now_ans++;
            if(now_ans>max_ans) max_ans = now_ans;
        }
        return max_ans;
    }
};