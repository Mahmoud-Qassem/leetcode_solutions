class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>freq;
        for(int num:nums){
            if(freq[num])return true;
            freq[num]|=1;
        }
        return false;
    }
};