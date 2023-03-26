//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


vector<int>vv;
long long dp[1001][1001];
int n;
class Solution {
private:
	long long solve(int sum, int idx)
	{
		//cout << idx << " " << sum << endl;
		if (sum==0)
		{
			return 1;
		}
		if (idx == n)return 0;

		auto&ret =dp[idx][sum];
		if (~ret)return ret;
		long long ans = 0;
		for (int i = idx; i < n; ++i)
		{
			if(sum>=vv[i])
			{
				ans+=solve(sum - vv[i], i);
			}
		}
		//cout << ret << endl;
		return ret=ans;
}

public:
	long long int count(int coins[], int N, int sum) {
		vv.resize(N);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; ++i)
			vv[i] = coins[i];
		n = N;
		return  solve(sum,0);
		
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends