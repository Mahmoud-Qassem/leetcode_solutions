class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int res = abs(arr[0]);
        int maxEnding = (arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            maxEnding = max(maxEnding + arr[i], arr[i] );
            res = max(res, abs(maxEnding));
        }
        maxEnding=arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxEnding = min(maxEnding + arr[i], arr[i] );
            res = max(res, abs(maxEnding));
        }
        return res;
    }
};