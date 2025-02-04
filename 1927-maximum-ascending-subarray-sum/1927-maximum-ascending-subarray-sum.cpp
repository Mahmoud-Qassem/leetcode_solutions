class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(),last,ans=nums[0];
        for(int i=0;i<n;++i){
            last=nums[i];
            int crnt=last;
            for(int j=i+1;j<n;++j){
                if(nums[j]>last)last=nums[j],crnt+=last;
                else break;
            }
            ans=max(ans,crnt);
        }
        return ans;
    }
};