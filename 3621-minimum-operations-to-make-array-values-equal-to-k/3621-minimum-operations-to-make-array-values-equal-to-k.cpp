class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        return (*s.begin()<k)?-1:(*s.begin()==k)?s.size()-1:s.size();
    }
};