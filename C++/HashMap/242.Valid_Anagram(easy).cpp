class Solution {
public:
    /*
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    使用哈希表判断两个字符串中字母出现次数是否一致即可；
    1. 新建map存放s中字母出现次数；
    2. 遍历t，当t中字母在哈希表中不存在或者个数为0时，返回false；
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, int> s_map;
        for(int i=0; i<s.length(); i++){
            if(s_map.find(s[i]) == s_map.end()){
                s_map[s[i]] = 1;
            }
            else s_map[s[i]]++;
        }
        for(int j=0; j<t.length(); j++){
            if(s_map.find(t[j]) == s_map.end() || s_map[t[j]]==0) return false;
            else s_map[t[j]]--;
        }
        return true;
    }
};