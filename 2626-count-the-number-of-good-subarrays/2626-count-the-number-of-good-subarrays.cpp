
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long left = 0, right = 0, n = nums.size(), cnt = 0, ans = 0;
        map<long long, long long> mp;
        while (left < n) {
            while (right < n and (cnt+ mp[nums[right]]) < k) {
                cnt += mp[nums[right]];
                mp[nums[right]]++;
                right++;
            }
            
            if (right <n and  (cnt+ mp[nums[right]]) >= k) {
                long long R = n - right;
                ans += R ;

            }
            mp[nums[left]]--;
            cnt -= mp[nums[left]];
            left++;
        }
        return ans;
    }
};