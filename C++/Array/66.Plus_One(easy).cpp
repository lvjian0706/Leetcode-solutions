class Solution {
public:
    /*
    给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
    1. 将该数组反转，编程从低位到高位的顺序；
    2. 进行加1运算，其中，定义flag变量用于记录是否进位，其中运算到最后如果flag等于1，说明答案数组比原始数组多1位，需要push_back(1)；
    3. 将结果数组反转；
    */
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int flag = 1;
        for(int i=0; i<digits.size(); i++){
            if((digits[i] + flag) >= 10){
                digits[i] = (digits[i] + flag) % 10;
            }
            else{
                digits[i] = digits[i] + flag;
                flag = 0;
            }
        }
        if(flag==1) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};