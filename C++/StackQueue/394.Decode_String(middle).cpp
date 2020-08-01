class Solution {
public:

    /*
    将字符串s重复n遍返回；
    */
    string repeatStr(string s, int n){
        string ans = "";
        for(int i=0; i<n; i++){
            ans.append(s);
        }
        return ans;
    }

    /*
    给定一个经过编码的字符串（编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。），返回它解码后的字符串：
    1. 使用栈来进行计算，建立两个栈分别存储k和encoded_string；
    2. 定义三个状态：BEGIN，NUMBER，CHARATOR分别代表起始状态，处理数字k，处理encoded_string；
    3. 遍历s，进行处理：
    3.1 BEGIN：判断第一个字符为数字还是encoded_string；
    3.2 NUMBER：将数字入nums栈；
    3.3 CHARATOR：
    3.3.1 s[i]!=']'时，将字符直接入dec_str栈；
    3.3.2 s[i]==']'时，解码字符串：
    3.3.2.1 取出字符串栈中的元素，直到取到'['为止，取出的元素则为需要重复的元素；
    3.3.2.2 将取出的字符连成字符串并重复n遍，n为nums栈中的栈顶元素；
    3.3.2.3 将新字符串入dec_str栈；
    4. dec_str中最后存储着解码后的字符串片段，拼接之后就是最终答案；
    */
    string decodeString(string s) {
        stack<int> nums;
        stack<string> dec_str;
        static const int BEGIN = 0;
        static const int NUMBER = 1;
        static const int CHARATOR = 2;
        int flag = BEGIN;
        for(int i=0; i<s.size(); i++){
            switch(flag){
                case BEGIN:{
                    if(s[i]>='0' && s[i]<='9') flag = NUMBER;
                    else flag = CHARATOR;
                    i--;
                    break;
                }
                case NUMBER:{
                    if(s[i]<'0' || s[i]>'9') flag = CHARATOR;
                    else{
                        int temp = 0;
                        while(s[i]>='0' && s[i]<='9'){
                            temp = temp * 10 + s[i] - '0';
                            i++;
                        }
                        nums.push(temp);
                    }
                    i--;
                    break;
                }
                case CHARATOR:{
                    if(s[i]>='0' && s[i]<='9'){
                        flag = NUMBER;
                        i--;
                    } 
                    else if(s[i]!=']'){
                        string mem;
                        mem.push_back(s[i]);
                        dec_str.push(mem);
                    }
                    else{
                        /*
                        1. 取出字符串栈中的元素，直到取到'['为止，取出的元素则为需要重复的元素；
                        2. 将取出的字符连成字符串并重复n遍，n为nums栈中的栈顶元素；
                        3. 将新字符串入dec_str栈；
                        */
                        string temp_str = "";
                        while(dec_str.top()[0]!='['){
                            string top_string = dec_str.top();
                            dec_str.pop();
                            temp_str.insert(0, top_string);
                        }
                        dec_str.pop(); //去掉'['
                        int times = nums.top();
                        nums.pop();
                        string repeat_str = repeatStr(temp_str, times);
                        dec_str.push(repeat_str);
                    }
                    break;
                }
            }
        }
        string ans = "";
        while(!dec_str.empty()){
            string mem_str = dec_str.top();
            dec_str.pop();
            ans.insert(0, mem_str);
        }
        return ans;
    }
};