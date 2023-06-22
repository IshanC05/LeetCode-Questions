class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        int i = 0, j = 0;
        while(j < n){
            if(prices[j] < prices[i]){
                i = j;
            }else if(prices[i] < prices[j]){
                profit = max(profit, prices[j] - prices[i]);
            }
            ++j;
        }
        return profit;
    }
};