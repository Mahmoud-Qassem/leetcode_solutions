class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>xr(501);
        for(auto&it:nums)xr[it]^=it;
        return !(*(max_element(xr.begin(),xr.end())));
    }
};