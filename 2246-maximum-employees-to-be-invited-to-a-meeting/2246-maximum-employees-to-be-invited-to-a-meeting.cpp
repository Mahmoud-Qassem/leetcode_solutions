int ans;
int timer=1;
vector<vector<int>>adjII;
vector<int>myPair;
vector<int>start_time,finish_time;


class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, int cnt=0) {

        start_time[node]=timer++;
        cnt++;
        for(auto&ne:adj[node]) {
            adjII[ne].push_back(node);
            if(not start_time[ne]) {
                dfs(ne,adj,cnt);
            }
            if(!finish_time[ne]) {
                // this is my parent in the path
                ans=max(ans,start_time[node]-start_time[ne]+1);
            }
        }
        cnt--;

        finish_time[node]=timer++;
    }
    int dfsII(int node,vector<bool>&visited) {

        visited[node]=true;
        int mx=0,cnt=1;
        
        for(auto&ne:adjII[node]) {
            if(not visited[ne] and node!=myPair[ne])
            mx=max(mx,dfsII(ne,visited));
        }
        
        return cnt+mx;
    }
    int maximumInvitations(vector<int>& favorite) {
        timer=1;
        adjII.clear();
        int n=favorite.size();
        myPair=vector<int>(n,-1);
        start_time=vector<int>(n);
        finish_time=vector<int>(n);
        vector<vector<int>>adj(n);
        adjII=vector<vector<int>>(n);
        
        
        // construct the adj list of the graph 
        for(int i=0;i<n;++i){
            int from=i;
            int to=favorite[i];
            adj[from].push_back(to);
        }
        ans=0;
        // dfs from every not visited  node to find the biggest cycle in the graph 
        
        for(int node=0;node<n;++node){
            if(!start_time[node]){
                dfs(node,adj);
            }
        }
        int biggest_cycle_nodes=ans;
        ////////////////////////////////////////////////////////////////////
        
        vector<int>pivots;
        for(int i=0;i<n;++i){
            if( favorite[ favorite[i] ]==i ){
                pivots.push_back(i);
                myPair[i]=favorite[i];
                myPair[favorite[i]]=i;
            }
        }
        int around_pivots_nodes=0;
        vector<bool>visited(n);
        for(int i=0;i<pivots.size();++i){
            int p1=pivots[i];
            int p2=favorite[ pivots[i] ];
            if(visited[p1])continue;
            int cntP1=dfsII(p1,visited);
            int cntP2=dfsII(p2,visited);
            around_pivots_nodes+=cntP1+cntP2;
        }
        
        return max(around_pivots_nodes,biggest_cycle_nodes);

    }
};