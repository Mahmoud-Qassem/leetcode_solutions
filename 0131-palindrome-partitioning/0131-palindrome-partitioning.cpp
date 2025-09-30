class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> current;
        
        // Step 1: Precompute palindrome substrings using DP
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }
        
        // Step 2: Backtracking with DP guidance
        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                ans.push_back(current);
                return;
            }
            for (int end = start; end < n; ++end) {
                if (isPal[start][end]) {
                    current.push_back(s.substr(start, end - start + 1));
                    dfs(end + 1);
                    current.pop_back();
                }
            }
        };
        
        dfs(0);
        return ans;
    }
};
