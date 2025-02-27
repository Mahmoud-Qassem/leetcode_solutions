class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int two = arr[j], one = arr[i];
                int prev = one + two;
                if (index.count(prev)) {
                    int k = index[prev];  
                    dp[j * n + k] = dp[i * n + j] + 1;
                    maxLen = max(maxLen, dp[j * n + k] + 2);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;  
    }
};
