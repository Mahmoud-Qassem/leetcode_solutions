//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
string s,t;
int n,m;
const int MX=1001;
int dp[MX][MX];
class Solution
{
private:
    int solve(int i,int j)
    {
        if(i==n or j==m)return 0;

        auto&ret=dp[i][j];
        if(~ret)return ret;
        int best=0;
        if(s[i]==t[j])
        {
            best=max(best,1+solve(i+1,j+1));
        }
        best=max(best,solve(i+1,j));
        best=max(best,solve(i,j+1));
        return ret=best;
    }


public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        s=s1,t=s2;
        n=x,m=y;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends