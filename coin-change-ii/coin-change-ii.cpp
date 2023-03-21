class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1));
        int dp[amount+1][coins.size()+1];
        dp[0][0]=0;
        for(int i=1;i<=coins.size();i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=amount;i++){
            dp[i][0]=0;
        }

        //dp[i][j] represents the the no. of ways to find sum i with the element lengths of j of coins
        for(int i=1;i<=amount;i++){
            for(int j=1;j<=coins.size();j++){
                dp[i][j]=dp[i][j-1];//not to include current element
                if(coins[j-1]<=i){
                    dp[i][j]+=dp[i-coins[j-1]][j];//include current element
                }
            }
        }
        return dp[amount][coins.size()];
        
    }
};