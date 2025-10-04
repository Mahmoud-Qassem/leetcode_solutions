class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();++i){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto pr:mp){
            int groupSize=pr.first;
            vector<int>tmp;
            for(int i=0;i<pr.second.size();++i){
                if(i and i%groupSize==0){
                    ans.push_back(tmp);
                    tmp.clear();
                }
                tmp.push_back(pr.second[i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};