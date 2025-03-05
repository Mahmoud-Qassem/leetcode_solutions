class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            if( nums[i]>0 and nums[i]<=n and nums[ nums[i]-1 ]!=nums[i] ){
                swap(nums[i],nums[nums[i]-1]);
                continue;
            }
            i++;
        }
        for(int i=0;i<n;++i)if(nums[i]!=i+1)return i+1;
        return n+1;

    }
};