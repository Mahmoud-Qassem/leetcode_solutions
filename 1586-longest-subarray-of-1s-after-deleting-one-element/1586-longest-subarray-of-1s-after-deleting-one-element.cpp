class Solution {
public:
    int longestSubarray(vector<int>& nums) {
           int left =0 , right=0;
           int n = nums.size();
           int zeros=0, ans=0;

           while(left< n ){
            while(right< n and (zeros+!nums[right])<2){
                zeros+=!(nums[right]);
                right++;
            }
            ans=max(ans, right-left-zeros);
            
            zeros-=!(nums[left]);
            left++;
           }
           if(ans==n)ans--;
           return ans;
    }
};