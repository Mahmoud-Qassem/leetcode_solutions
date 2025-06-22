class Solution {
    public int[] getConcatenation(int[] nums) {
        int ans[]=Arrays.copyOf(nums,2*nums.length);
        System.arraycopy(nums,0,ans,nums.length,nums.length);
        return ans;
    }
    
}