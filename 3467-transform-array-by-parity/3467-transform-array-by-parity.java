class Solution {
    public int[] transformArray(int[] nums) {
        int n = nums.length;
        int odds=(int)Arrays.stream(nums).filter(x->x%2!=0).count();
        odds=n-odds;
        System.out.print(odds);
        int ans[]=new int[n];
        Arrays.fill(ans,1);
        Arrays.fill(ans, 0, odds,0);
        return ans;
    }
}