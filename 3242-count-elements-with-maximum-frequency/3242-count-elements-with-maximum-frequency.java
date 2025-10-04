class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] frq = new int[101];int  mxFrq=0;

        for(int i=0;i<nums.length;++i){
            frq[ nums[i] ]++;
            mxFrq=Math.max(frq[ nums[i] ], mxFrq);
        }
        int ans=0;
        for(int i=0;i<101;++i){
            if(mxFrq==frq[i]){
                ans++;
            }
        }
        return ans*mxFrq;

    }
}