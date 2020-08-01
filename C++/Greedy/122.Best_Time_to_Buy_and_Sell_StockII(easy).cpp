方法一：峰顶峰谷

class Solution {
public:
    /*
    买卖股票的最佳时机：可以尽可能地完成更多的交易；
    方法一：可以将价格绘制出来，在拐点处进行买卖即可，极小值点买极大值点卖可以获得最大利润；
    编程实现上，当后一个元素大于该元素且前一个元素大于等于该元素时，为极小值点，当前一个元素小于当前元素且后一个元素小于等于该元素时为极大值点；
    当极大值更新时，说明卖出了股票，更新收益值。
    其中，起始值和末尾值需要单独判断，当起始值后的元素大于该元素时，该元素为极小值，否则极小值初始化为0即可；当末尾值大于前一个元素时，该元素为极大值。
    */
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int ans = 0;
        int min_price = 0, max_price = 0;
        if(prices[1]>prices[0]) min_price = prices[0];
        for(int i = 1; i<prices.size()-1; i++){
            if(prices[i-1]>=prices[i] && prices[i+1]>prices[i]){
                min_price = prices[i];
            }
            if(prices[i-1]<prices[i] && prices[i+1]<=prices[i]){
                max_price = prices[i];
                ans += (max_price - min_price);
            }
        }
        if(prices[prices.size()-1]>prices[prices.size()-2]){
            max_price = prices[prices.size()-1]; 
            ans += (max_price - min_price);
        } 
        return ans;
    }
};


方法二：简化版
class Solution {
public:
    /*
    买卖股票的最佳时机：可以尽可能地完成更多的交易；
    方法二：可以将价格绘制出来，只要上涨就记录收益，下跌时不管
    */
    int maxProfit(vector<int>& prices) {
        int all_profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0) all_profit += prices[i]-prices[i-1];
        }
        return all_profit;
    }
};