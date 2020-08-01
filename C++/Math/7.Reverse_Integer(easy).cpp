class Solution {
public:
    /*
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
    问题本身很简单，难点在判断溢出情况：
    1. 当前结果如果大于INT_MAX / 10，则下一步乘10后一定溢出；
    2. 当前结果如果等于INT_MAX / 10，则下一位如果大于7会溢出；
    3. 当前结果如果小于INT_MIN / 10，则下一步乘10后一定溢出；
    4. 当前结果如果等于INT_MIN / 10，则下一位如果小于-8会溢出；
    */
    int reverse(int x) {
        int ans = 0;
        while(x){
            if(ans > INT_MAX / 10){
                ans = 0;
                break;
            }
            else if(ans == INT_MAX / 10 && (x % 10)>7){
                ans = 0;
                break;
            }
            else if(ans < INT_MIN / 10){
                ans = 0;
                break;
            }
            else if(ans == INT_MIN / 10 && (x % 10)<-8){
                ans = 0;
                break;
            }
            else{
                ans = ans * 10 + (x % 10);
                x /= 10;
            }
        }
        return ans;
    }
};