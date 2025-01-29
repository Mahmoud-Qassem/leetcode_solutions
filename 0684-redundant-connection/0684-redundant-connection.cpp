class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>adj(1001);
        vector<bool>visited(1001);

        for(auto&edge:edges){
            // reverse the edges
            int from= edge[1];
            int to= edge[0];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        stack<int>Stack;
        vector<bool>cycle_node(1001);
        auto dfs = [&](auto dfs, int node,int parent)->void{
            visited[node]=true;
            Stack.push(node);

            for(auto&ne:adj[node]){
                if(not visited[ne]){
                    dfs(dfs,ne,node);
                }
                else if(ne!=parent and not cycle_node[ne]){
                    while(Stack.size()){
                        cycle_node[Stack.top()]=true;
                        if(Stack.top()==ne)break;
                        Stack.pop();
                    }
                }
            }
 
            if(Stack.size())Stack.pop();
        };
        
        dfs(dfs,1,1);

        for(int i=edges.size()-1;i>=0;--i){
            auto edge=edges[i];

            int from= edge[0];
            int to= edge[1];
            if(cycle_node[from] and cycle_node[to]){
                return {from,to};
            }
            
        }
        
        
        return {1,2};
    }
};