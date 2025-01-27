class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>rows(n),cols(m);
        for(int i=0;i<n;++i){
            int sum=0;
            for(int j=0;j<m;++j){
                sum+=grid[i][j];
            }
            rows[i]=sum;
        }
        for(int i=0;i<m;++i){
            int sum=0;
            for(int j=0;j<n;++j){
                sum+=grid[j][i];
            }
            cols[i]=sum;
        }

        
        int communicate_servers=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] and (rows[i]-1 or cols[j]-1)){
                    communicate_servers++;
                }
            }
        }
        return communicate_servers;
    }
};