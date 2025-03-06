class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeated=-1, missed=0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j]-1;
                int x = num / n;
                int y = num % n;
                //cout<<x<<" "<<y<<endl;
                if (x == i and y == j)
                    continue;
                if (grid[x][y] == num+1) {
                    repeated = num+1;
                    continue;
                }
                swap(grid[x][y], grid[i][j]);
                j--;
            }
        }
        for (int i = 0; i < n and !missed; ++i) {
            for (int j = 0; j < n; ++j) {
                int crnt=i*n+j+1;
                if(grid[i][j]!=crnt){
                    missed=crnt;
                    break;
                }
            }
        }
        return {repeated,missed};
    }
};