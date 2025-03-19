class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0,n=nums.size();
        for(int i=0;i<n-2;++i){
            if(!nums[i]){
                nums[i+1]^=1;
                nums[i+2]^=1;
                cnt++;
            }
        }
        if(!nums[n-1] or !nums[n-2])
        return -1;
        return cnt;
    }
};