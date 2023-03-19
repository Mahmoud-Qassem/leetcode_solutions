class Solution {
public:
    int search(vector<int>& nums, int target) {
//        bool flag=binary_search(nums.begin(),nums.end(),target);
//        if(not flag)return -1;
        int ans=find(nums.begin(),nums.end(),target)-nums.begin();
        if(ans==nums.size())return -1;
        return ans;
    }
};