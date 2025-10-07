
class Solution {
public:
    int shortestSubarray(vector<int>& nums,int target) {
        int ans=INT_MAX;
        int n = nums.size();
        long long crntSum=0;
        priority_queue<pair<long long, int>, std::vector<pair<long long, int>>, std::greater<pair<long long, int>>>pq;
        for(int r=0;r<n;++r){
            crntSum+=nums[r];
            if(crntSum>=target){
                ans=min(ans, r+1);
            }
            while( pq.size() and (crntSum-pq.top().first>=target) ){
                auto [prefixSum, idx]=pq.top();
                ans=min(ans, r-idx);
                pq.pop();
            }
            
            pq.push({crntSum, r});
        }
        return ans==INT_MAX?-1:ans;
            
    }
};