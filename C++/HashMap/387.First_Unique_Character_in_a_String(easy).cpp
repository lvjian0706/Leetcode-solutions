class Solution {
public:
    /*
    找到字符串的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
    使用哈希表遍历两遍字符串即可；
    第一遍遍历保存字符出现次数，第二次遍历找第一个出现次数为1的字符；
    */
    int firstUniqChar(string s) {
        map<char, int> num_char;
        for(int i=0; i<s.length(); i++){
            if(num_char.find(s[i]) == num_char.end()){
                num_char[s[i]] = 1;
            }
            else num_char[s[i]]++;
        }
        for(int i=0; i<s.length(); i++){
            if(num_char[s[i]]==1) return i;
        }
        return -1;
    }
};