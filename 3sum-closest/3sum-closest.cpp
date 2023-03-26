#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        int closestDiff = INT_MAX;
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = std::abs(sum - target);
                
                if (diff < closestDiff) {
                    closestSum = sum;
                    closestDiff = diff;
                }
                
                if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        
        return closestSum;
    }
};