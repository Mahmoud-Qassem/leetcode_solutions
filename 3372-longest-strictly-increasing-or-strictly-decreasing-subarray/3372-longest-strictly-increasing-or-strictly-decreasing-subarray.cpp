class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),ans=1;
        for(int i=0;i<n;++i){
            int start=nums[i],cnt=1;
            for(int j=i+1;j<n;++j){
                if(nums[j]>start){
                    cnt++;
                    start=nums[j];
                }
                else break;
            }
            ans=max(ans,cnt);
        }
        for(int i=0;i<n;++i){
            int start=nums[i],cnt=1;
            for(int j=i+1;j<n;++j){
                if(nums[j]<start){
                    cnt++;
                    start=nums[j];
                }
                else break;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};