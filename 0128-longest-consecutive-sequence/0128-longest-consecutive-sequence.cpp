class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = 0;
        int cnt = 0;
        if(nums.size() == 0){
            return 0;
        }
        for(int i =1; i<nums.size();i++){
           if(nums[i-1]+1 < nums[i]){
            cnt = 0;
           }
           else if(nums[i-1]==nums[i]){
            continue;
           }
           else{
             cnt++;
             len = max(cnt,len);
           }
        }
        return len+1;
    }
};