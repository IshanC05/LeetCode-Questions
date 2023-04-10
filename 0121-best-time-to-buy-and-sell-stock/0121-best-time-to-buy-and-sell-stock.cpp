class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=1, ans = 0;
        while(j < prices.size()){
            if(prices[i] > prices[j]){
                i = j;
            }else{
                ans = max(ans, prices[j] - prices[i]);
            }
            ++j;
        }
        return ans;
    }
};