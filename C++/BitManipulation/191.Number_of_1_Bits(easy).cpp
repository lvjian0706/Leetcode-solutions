方法1：
class Solution {
public:
    /*
    返回二进制表达式中数字位数为 ‘1’ 的个数:
    求二进制数（对2取余后整除2），当该位为1时，ans++；
    */
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n!=0){
            ans += (n % 2);
            n /= 2;
        }
        return ans;
    }
};

方法2：
class Solution {
public:
    /*
    返回二进制表达式中数字位数为 ‘1’ 的个数:
    n = n & (n-1) : 将最后一个1置0；
    将最后一个1循环置0，直到所有位上都是0；
    */
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
};