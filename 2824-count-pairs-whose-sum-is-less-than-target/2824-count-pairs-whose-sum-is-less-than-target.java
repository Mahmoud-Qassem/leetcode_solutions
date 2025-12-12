class Solution {
    static int lower_bound(List<Integer> array,int limit, int key)
    {
        int low = 0, high = limit;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;

            if (key <= array.get(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        if (low < array.size() && array.get(low) < key) {
            low++;
        }
        return low;
    }
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int ans=0;
        for(int i=0;i<nums.size();++i){
            int diff = target-nums.get(i);
            int lo=lower_bound(nums, nums.size(), diff);
            if(lo>i)lo--;
            ans+=lo;
        }
        return ans/2;
    }
}