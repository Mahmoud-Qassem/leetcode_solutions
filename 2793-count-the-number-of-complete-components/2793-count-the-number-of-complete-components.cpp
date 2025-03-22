class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        // Building adjacency list
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 0;

        // DFS Function
        auto dfs = [&](auto&& dfs, int node, int& crntNodes, int& crntEdges) -> void {
            visited[node] = true;
            crntNodes++; // Counting the node
            for (int ne : adj[node]) {
                crntEdges++; // Count edges
                if (!visited[ne]) {
                    dfs(dfs, ne, crntNodes, crntEdges);
                }
            }
        };

        // Iterate through all nodes
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                int crntNodes = 0, crntEdges = 0;
                dfs(dfs, node, crntNodes, crntEdges);

                // Since edges are counted twice, divide by 2
                if (crntEdges / 2 == (crntNodes * (crntNodes - 1)) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
