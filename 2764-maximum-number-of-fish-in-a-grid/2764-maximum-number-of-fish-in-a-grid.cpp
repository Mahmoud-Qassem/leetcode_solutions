class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        
        int sum=0,ans=0,n=grid.size(),m=grid[0].size();
        auto dfs=[&](auto dfs, int x, int y)->void{
            sum+=grid[x][y];
            grid[x][y]=0;
            
            for(int i=0;i<4;++i){
                int xx=x+dx[i];
                int yy=y+dy[i];
                
                if( (xx>=0 and yy>=0 and xx<n and yy<m) and grid[xx][yy]  ){
                    dfs(dfs,xx,yy);
                }
            }
        };
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]){
                    sum=0;
                    dfs(dfs,i,j);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};