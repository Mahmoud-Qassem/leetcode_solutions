class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> mergedMap(2005, 0);
        
        // Insert values from the first array into the vector
        for (const auto& pair : nums1) {
            mergedMap[pair[0]] += pair[1];
        }
        // Insert values from the second array into the vector
        for (const auto& pair : nums2) {
            mergedMap[pair[0]] += pair[1];
        }
        // Convert the vector to the resulting vector of vectors
        vector<vector<int>> result;
        for (int i = 0; i < mergedMap.size(); ++i) {
            if (mergedMap[i]) {
                result.push_back({i, mergedMap[i]});
            }
        }
        return result;
    }
};