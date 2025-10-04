class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int operations=0;
        for(int x:nums){
            int rem=x%3;
            operations+=min(rem,3-rem);
        }
        return operations;
    }
};