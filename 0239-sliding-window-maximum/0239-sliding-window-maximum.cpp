class Solution {
    void construct_segment_tree(vector<int>& segtree, vector<int>& a, int n) {
        for (int i = 0; i < n; i++)
            segtree[n + i] = a[i];
        for (int i = n - 1; i >= 1; i--)
            segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);
    }

    int range_query(vector<int>& segtree, int left, int right, int n) {

        left += n;
        right += n;

        // initialize maximum to a very low value
        int ma = INT_MIN;

        while (left < right) {

            // if left index in odd
            if (left & 1) {
                ma = max(ma, segtree[left]);

                // make left index even
                left++;
            }

            // if right index in odd
            if (right & 1) {

                // make right index even
                right--;

                ma = max(ma, segtree[right]);
            }

            // move to the next higher level
            left /= 2;
            right /= 2;
        }
        return ma;
    }

public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();

        /* Construct the segment tree by assigning
        the values to the internal nodes*/
        vector<int> segtree(2 * n);
        construct_segment_tree(segtree, a, n);

        vector<int> ans;
        k--;
        for (int i = 0; i + k < n; ++i) {
        ans.push_back(range_query(segtree, i,i+k + 1, n));
        }
        return ans;
    }
};
