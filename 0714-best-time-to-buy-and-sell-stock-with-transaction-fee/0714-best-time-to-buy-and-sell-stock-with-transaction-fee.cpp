class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buyprofit=INT_MIN;
        int sellprofit=0;
        for(auto price : prices){
            buyprofit = max(buyprofit,sellprofit-price);
            sellprofit = max(sellprofit , buyprofit+price-fee);
        }
        return sellprofit;
    }
};