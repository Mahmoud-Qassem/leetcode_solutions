class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxMoney=0;
        for(auto money:accounts){
            int sum = accumulate(money.begin(), money.end(), 0);
            maxMoney=max(maxMoney, sum);
        }
        return maxMoney;
    }
};