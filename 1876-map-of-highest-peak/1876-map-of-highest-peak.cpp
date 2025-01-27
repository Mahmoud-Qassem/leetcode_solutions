class Solution {
public:
    vector<int>dx= {0,0,1,-1};
    vector<int>dy= {1,-1,0,0};
    bool valid(int x, int y, int n, int m) {
        return (x>=0 and y>=0 and x<n and y<m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        queue<pair<int,int>>q;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(isWater[i][j]==1) {
                    isWater[i][j]=0;
                    q.push({i,j});
                } else {
                    isWater[i][j]=-1;
                }
            }
        }

        for(int lvl=0,sz=q.size(); sz; sz=q.size(),lvl++) {
            while(sz--) {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int d=0; d<4; ++d) {
                    int new_x=dx[d]+i;
                    int new_y=dy[d]+j;
                    if(valid(new_x,new_y,n,m) and isWater[new_x][new_y]==-1) {
                        isWater[new_x][new_y]=isWater[i][j]+1;
                        q.push({new_x,new_y});
                    }
                }
            }
        }

        return isWater;
    }
};