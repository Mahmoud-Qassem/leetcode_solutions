class Solution {
public:

    bool zero(vector<int> nums, vector<vector<int>>& queries, int limit){
        int n=nums.size();
        vector<int>pref(n+1);
        // n to calculate the first LIMIT queries 
        for(int i=0;i<limit;++i){
            pref[queries[i][0]]--;
            pref[queries[i][1]+1]++;
        }
        
        // n to apply the prefix sum on the first LIMIT
        for(int i=1;i<n;++i)pref[i]+=pref[i-1];
        // n to add the prefix sum on nums
        for(int i=0;i<n;++i){
            nums[i]+=pref[i];
            nums[i]=max(0,nums[i]);
        }
        // n to check if max of nums is zero or not
        int mx=*max_element(nums.begin(),nums.end());
        return !mx;
        // with total of O(4n)
        
        
        
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),q=queries.size();
        int left=0, right=q,ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(zero(nums,queries, mid)){
                return 1;
                right=mid-1;
            }
            else left=mid+1;
        }
        return 0;
    }
};