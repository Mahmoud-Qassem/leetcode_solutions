class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<vector<long long>>prefix(2,vector<long long>(n+10));
        // from right to left <=== prefix
        for(int i=0; i<2; ++i) {
            for(int j=n-1; j>=0; --j) {
                prefix[i][j]+=prefix[i][j+1]+grid[i][j];
            }
        }
        
        long long min_score=LLONG_MAX;
        
        for(int i=0;i<n;++i){
            long long lower_left=prefix[1][0]-prefix[1][i];
            long long upper_right=prefix[0][i+1];
            min_score=min(min_score,max(lower_left,upper_right));
        }
        return min_score;
    }
};