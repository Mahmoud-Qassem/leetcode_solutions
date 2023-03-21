vector<int>v;
int n,c=0;
const long long MX=5005,MXLAST=305;
long long dp[MX][MXLAST];
class Solution
{

private:
    long long solve(long long x, int last)
    {
        if (x < 0) return 0;
        if (x == 0)return 1;


        auto&ret=dp[x][last];
        if(~ret)return ret;


        long long best = 0;


        for(int i=last; i<n; ++i)
        {
            best+=solve(x-v[i],i);
        }
        return ret=best;
    }


public:
    int change(int amount,vector<int>& coins)
    {
        v=coins;
        n=v.size();
        memset(dp,-1,sizeof(dp));
        return solve(amount,0);
    }
};