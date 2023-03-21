vector<int>v;
int n,c=0;
const long long MX=10005;
long long dp[MX][15];
class Solution
{

private:
    long long solve(long long remain,long long ih)
    {
        if(remain==0 and ih==n)return 0;
        if(ih==n)return INT_MAX;


        auto&ret=dp[remain][ih];
        if(~ret)return ret;

        long long mn=INT_MAX;
        long long idx=1;
        while(v[ih]*idx <=remain and ih<n )
        {
            mn=min(mn,idx+solve( (remain-(v[ih]*idx)) , ih+1 ));
            idx++;
        }
        mn=min(mn,solve( remain , ih+1 ));




        return ret=mn;
        // 1 2 5
    }


public:
    int coinChange(vector<int>& coins, int amount)
    {
        v=coins;
        n=v.size();
        memset(dp,-1,sizeof(dp));
        int tmp=solve(amount,0);
        return tmp==INT_MAX?-1:tmp;
    }
};