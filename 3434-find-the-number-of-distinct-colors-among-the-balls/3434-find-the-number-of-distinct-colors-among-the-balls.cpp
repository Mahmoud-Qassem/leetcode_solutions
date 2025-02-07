class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        unordered_map<int,int>mp,colors;
        vector<int> dist(n);

        for (int i = 0; i < n; ++i) {
            int node = queries[i][0];
            int color = queries[i][1];
            int crnt = -1;
            if (mp[node]) {
                crnt = mp[node];
            }
            if (crnt != -1) {
                colors[crnt]--;
                if (!colors[crnt])
                    colors.erase(colors.find(crnt));
            }
            colors[color]++;
            mp[node] = color;
            dist[i] = colors.size();
        }
        return dist;
    }
};