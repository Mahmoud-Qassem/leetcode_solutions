
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>mx(n);
        int x=0;
        for(int i=n-1;i>=0;--i)
        {
            x=max(x,prices[i]);
            mx[i]=x;
        }
        int ans=0;
        for(int i=0;i<n-1;++i)
        {
            ans=max(ans,(mx[i+1]-prices[i]));
        }
        return ans;
    }
};