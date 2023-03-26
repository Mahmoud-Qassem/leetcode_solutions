#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(), v.end()); // Sort the vector to enable two-pointer approach
        int n = v.size();
        long long closest_sum = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                long long sum = v[i] + v[left] + v[right];
                if (abs(sum - target) < abs(closest_sum - target)) {
                    closest_sum = sum;
                }
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else { // sum == target
                    return target;
                }
            }
        }
        return closest_sum;
    }
};
