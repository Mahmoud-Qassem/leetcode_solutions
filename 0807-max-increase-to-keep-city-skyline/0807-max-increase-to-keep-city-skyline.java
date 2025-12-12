class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int n = grid.length;
        int[] rowsMaxs= new int[n];
        int[] colsMaxs=new int[n];
        for(int i=0;i<n;++i){
            int mx =0;
            for(int j=0;j<n;++j)mx=Math.max(mx,grid[i][j]);
            rowsMaxs[i]=mx;
        }
        for(int i=0;i<n;++i){
            int mx =0;
            for(int j=0;j<n;++j)mx=Math.max(mx,grid[j][i]);
            colsMaxs[i]=mx;
        }
        int maxIncrease=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int mn =Math.min(rowsMaxs[i], colsMaxs[j]);
                if(mn>grid[i][j])maxIncrease+=mn-grid[i][j];
            }
        }
        return maxIncrease;
        
    }
}