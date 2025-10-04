class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        map<int,int>mp;
        int ans=0;
        for(int x:nums){
            for(auto pr:mp){
                int key=pr.first;
                int value = pr.second;
                if(key+x<target)ans+=value;
            }
            mp[x]++;
        }
        return ans;
    }
};