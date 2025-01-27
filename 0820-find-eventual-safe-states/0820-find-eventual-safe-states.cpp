int timer=1;
vector<int>start_time,finish_time,save_nodes;
deque<int>q;
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj)
    {

        start_time[node]=timer++;
        q.push_back(node);
        
        for(auto&ne:adj[node]){
            if(not start_time[ne]){
                dfs(ne,adj);
            }
            if(!finish_time[ne] or !save_nodes[ne]){
                // this is my parent in the path
                while(!q.empty()){
                    int tp=q.back();
                    save_nodes[tp]=0;
                    q.pop_back();
                }
            }
        }
        if(!q.empty())
        q.pop_back();
        
        finish_time[node]=timer++;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Let us assume the All nodes that are in a cycle are not a safe nodes
        timer=1;
        while(!q.empty())q.pop_back();
        int n=graph.size();
        start_time=vector<int>(n,0);
        save_nodes=vector<int>(n,1);
        finish_time=vector<int>(n,0);
        for(int i=0;i<n;++i){
            if(!start_time[i]){
                dfs(i,graph);
            }
        }
        vector<int>res;
        for(int i=0;i<n;++i){
            if(save_nodes[i])res.push_back(i);
        }
        sort(res.begin(),res.end());
        return res;



    }
};