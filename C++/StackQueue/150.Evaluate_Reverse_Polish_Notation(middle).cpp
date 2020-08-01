class Solution {
public:
    /*
    逆波兰表达式求值：
    使用栈来存储每个数字以及当前的计算结果；为了方便定义flag标志位，使用switch语句进行判断；
    1. 当字符串长度大于1或字符串的第一个元素大于‘0’小于‘9’时，说明字符串中为数字，将string转为int后入栈；（注意处理2位数以上的数以及负数）
    2. 当字符串中存储的是运算符：将栈顶的两个元素取出后进行计算，结果重新入栈；
    3. 栈顶元素为最终结果；
    */
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        static const int NUMBER = 1;
        static const int OPERATOR = 2;
        int flag = NUMBER;
        for(int i=0; i<tokens.size(); i++){
            string mem = tokens[i];
            if(mem.size()>1 || (mem[0]>='0' && mem[0]<='9')) flag = NUMBER;
            else flag = OPERATOR;
            switch(flag){
                case NUMBER:{
                    int j=0, temp=0;
                    if(mem[0]=='-') j++;
                    while(mem[j]>='0' && mem[j]<='9'){
                        temp = temp * 10 + mem[j] - '0';
                        j++;
                    }
                    if(mem[0]=='-') nums.push(0-temp);
                    else nums.push(temp);
                    break;
                }
                case OPERATOR:{
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    if(mem[0]=='+') nums.push(num2+num1);
                    else if(mem[0]=='-') nums.push(num2-num1);
                    else if(mem[0]=='*') nums.push(num2*num1);
                    else if(mem[0]=='/') nums.push(num2/num1);
                    break;
                }
            }
        }
        return nums.top();
    }
};