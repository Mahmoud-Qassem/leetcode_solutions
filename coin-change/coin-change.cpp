vector<int>v;
int n,c=0;
const long long MX=10005;
long long dp[MX];
class Solution
{

private:
    long long solve(long long x)
    {
        if (x < 0) return INT_MAX;
        if (x == 0) return 0;
        auto&ret=dp[x];
        if(~ret)return ret;
        long long best = INT_MAX;
        for (auto c : v)
        {
            best = min(best, solve(x-c)+1);
        }
        return ret=best;
    }


public:
    int coinChange(vector<int>& coins, int amount)
    {
        v=coins;
        n=v.size();
        memset(dp,-1,sizeof(dp));
        int tmp=solve(amount);
        return tmp==INT_MAX?-1:tmp;
    }
};