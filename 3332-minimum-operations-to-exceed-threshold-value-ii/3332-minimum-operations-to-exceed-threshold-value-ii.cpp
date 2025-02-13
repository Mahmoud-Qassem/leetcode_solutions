class Solution {
public:
    int minOperations(vector<int>& nums, unsigned k) {
        auto a = nums.data();
        int n = remove_if(a, a + nums.size(), [=](int x){return x >= k; }) - a;
        make_heap(a, a + n, greater{});
        int ans = 0;
        while (n > 1) {
            int x = a[0]; pop_heap(a, a + n--, greater{});
            int y = a[0]; pop_heap(a, a + n--, greater{});
            ++ans;
            if (x * 2u + y < k) {
                a[n++] = x * 2u + y;
                push_heap(a, a + n, greater{});
            } else break;
        }
        return ans + (n + 1) / 2;
    }
};