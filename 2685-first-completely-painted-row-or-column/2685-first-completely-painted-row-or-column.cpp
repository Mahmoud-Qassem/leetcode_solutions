class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>>mp(n*m+1);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mp[ mat[i][j] ]={i,j};
            }
        }
        vector<int>rows(n),cols(m);
        for(int i=0;i<n*m;++i){
            int row=mp[arr[i]].first,col=mp[arr[i]].second;
            rows[row]++;
            cols[col]++;
            if(rows[row]==m or cols[col]==n)return i;
        }
        return -1;
    }
};