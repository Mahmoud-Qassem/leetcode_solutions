import java.util.HashMap;

class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        /*
        [0,0,0,0]
        0
        */
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0,1);
        
        long n= nums.length;
        int ans =0;
        for(int i= 1 ;i<n;++i)nums[i]+=nums[i-1];
        for(int i=0;i<n;++i){
            int  x= mp.getOrDefault( nums[i]-goal, 0 );
            ans+= x;
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        return ans;


    }
}