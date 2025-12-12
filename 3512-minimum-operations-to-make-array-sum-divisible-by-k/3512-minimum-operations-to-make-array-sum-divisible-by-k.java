class Solution {
    public int minOperations(int[] nums, int k) {
        return (int)(((int) Arrays.stream(nums).sum())%k);
    }
}