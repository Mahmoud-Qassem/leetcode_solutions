class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mn=INT_MAX;
        for(auto&price:prices){
            profit=max(profit, price-mn);
            mn=min(price,mn);
        }
        return profit;

    }
};
