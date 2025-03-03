class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int eq=0;
        vector<int>res;
        for(auto&it:nums)if(it<pivot)res.push_back(it);else if(it==pivot)eq++;
        while(eq--)res.push_back(pivot);
        for(auto&it:nums)if(it>pivot)res.push_back(it);
        return res;
        
    }
};