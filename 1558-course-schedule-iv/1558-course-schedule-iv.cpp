static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, 
                                     vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        vector<bool>ans(queries.size()),visited(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto&edge:prerequisites){
            // reverse the edges
            int from= edge[1];
            int to= edge[0];
            adj[from].push_back(to);
        }
        
        
        
        vector<vector<int>>depend(numCourses,vector<int>(numCourses));
        auto dfs = [&](auto dfs, int node,int&parent)->void{
            visited[node]=true;
            depend[parent][node]=true;
            for(auto&ne:adj[node]){
                if(not visited[ne]){
                    dfs(dfs,ne,parent);
                }
            }
        };
        
        for(int i=0;i<numCourses;++i){
            visited=vector<bool>(numCourses);
            
            dfs(dfs,i,i);
        }
        
        int idx=0;
        for(auto&query:queries){
            int from =query[1];
            int to =query[0];
            ans[idx++]=depend[from][to];
        }
        
        return ans;
    }
};