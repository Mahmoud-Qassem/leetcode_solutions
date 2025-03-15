class Solution {
public:
    bool check(vector<int>& nums, int k, int limit) {
        int n = nums.size();
        for (int i = 0; i < n and k and (n-i)>=k; ++i) {
            if (nums[i] <= limit) {
                i++;
                k--;
            }
        }
        return not k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), ans;
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, k, mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};