
class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> sizeOfGroup;
        vector<int> anding;
        DSU(int N) {
            parent.resize(N + 5);
            anding.resize(N + 5);
            sizeOfGroup.resize(N + 5);

            for (int i = 0; i < N; i++) {
                parent[i] = i;
                anding[i]=-1;
                sizeOfGroup[i] = 1;
            }
        }
        int getLeader(int i) {
            if (i == parent[i])
                return i;
            else
                return parent[i] = getLeader(parent[i]);
        }
        bool sameGroup(int x, int y) { return getLeader(x) == getLeader(y); }

        void mergeGroup(int x, int y, int w) {
            int leader1 = getLeader(x);
            int leader2 = getLeader(y);
            if (leader1 == leader2) {
                anding[leader1] &= w;
                return;
            }

            else if (sizeOfGroup[leader1] > sizeOfGroup[leader2]) {
                parent[leader2] = leader1;
                anding[leader1] &= anding[leader2] & w;
                 sizeOfGroup[leader1] +=
                    sizeOfGroup[leader2];
            } else {
                parent[leader1] = leader2;
                anding[leader2] =anding[leader2] & w & anding[leader1];
                 sizeOfGroup[leader2] +=
                    sizeOfGroup[leader1];
            }
        }
        int getSize(int x) { return sizeOfGroup[getLeader(x)]; }
        int getAnd(int x) { return anding[getLeader(x)]; }
    };

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<int> ans;
        DSU dsu(n);
        for(auto&edge:edges){
            dsu.mergeGroup(edge[0],edge[1],edge[2]);
        }
        for(auto&q:query){
            if(!dsu.sameGroup(q[0],q[1])){
                cout<<dsu.getLeader(q[0])<<endl;
                cout<<dsu.getLeader(q[1])<<endl;
                ans.push_back(-1);
                }
            else {
                ans.push_back(dsu.getAnd(q[0]));
            }
        }

        return ans;
    }
};