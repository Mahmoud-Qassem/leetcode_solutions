const int MAX = 100001;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bitset<MAX>bts(0);
        vector<int>ans;
        for(int x:nums){
            if(bts[x]){
                ans.push_back(x);
            }
            bts.set(x);
        }
        return ans;
    }
};