class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mergedMap;
        // Insert values from the first array into the map
        for (const auto& pair : nums1) {
            mergedMap[pair[0]] += pair[1];
        }
        // Insert values from the second array into the map
        for (const auto& pair : nums2) {
            mergedMap[pair[0]] += pair[1];
        }
        // Convert the map to the resulting vector of vectors
        vector<vector<int>> result;
        for (const auto& [id, val] : mergedMap) {
            result.push_back({id, val});
        }
        return result;
    }
};