class Solution {

    int getMid(int s, int e) { return s + (e - s) / 2; }

    int MaxUtil(int* st, int ss, int se, int l, int r, int node) {

        if (l <= ss && r >= se)
            return st[node];

        // If segment of this node does not
        // belong to given range
        if (se < l || ss > r)
            return INT_MIN;

        // If segment of this node is partially
        // the part of given range
        int mid = getMid(ss, se);

        return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1),
                   MaxUtil(st, mid + 1, se, l, r, 2 * node + 2));
    }

    /* A recursive function to update the nodes
    which have the given index in their range.
    The following are parameters st, ss and
    se are same as defined
    above index -> index of the element
    to be updated.*/
    void updateValue(int arr[], int* st, int ss, int se, int index, int value,
                     int node) {


        if (ss == se) {
            // update value in array and in segment tree
            arr[index] = value;
            st[node] = value;
        } else {
            int mid = getMid(ss, se);

            if (index >= ss && index <= mid)
                updateValue(arr, st, ss, mid, index, value, 2 * node + 1);
            else
                updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2);

            st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        }
        return;
    }

    // Return max of elements in range from
    // index l (query start) to r (query end).
    int getMax(int* st, int n, int l, int r) {
        // Check for erroneous input values

        return MaxUtil(st, 0, n - 1, l, r, 0);
    }

    // A recursive function that constructs Segment
    // Tree for array[ss..se]. si is index of
    // current node in segment tree st
    int constructSTUtil(int arr[], int ss, int se, int* st, int si) {
        // If there is one element in array, store
        // it in current node of
        // segment tree and return
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements, then
        // recur for left and right subtrees and
        // store the max of values in this node
        int mid = getMid(ss, se);

        st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                     constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));

        return st[si];
    }

    /* Function to construct segment tree
    from given array.
    This function allocates memory for
    segment tree.*/
    int* constructST(int arr[], int n) {
        // Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        // Allocate memory
        int* st = new int[max_size];

        // Fill the allocated memory st
        constructSTUtil(arr, 0, n - 1, st, 0);

        // Return the constructed segment tree
        return st;
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int arr[n];
        for(int i=0;i<n;++i)arr[i]=nums[i];
        k--;
        int* st = constructST(arr, n);
        vector<int>ans;
        for(int i=0;i+k<n;++i){
            ans.push_back(getMax(st, n, i, i+k));

        }
        return ans;
    }
};
