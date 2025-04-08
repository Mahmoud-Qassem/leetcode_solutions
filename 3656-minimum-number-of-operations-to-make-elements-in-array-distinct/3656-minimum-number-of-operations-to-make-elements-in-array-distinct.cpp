class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>frq(101);
        for(int i=n-1;i>=0;--i){
            if(frq[nums[i]]){
                return (i+3)/3;
            }
            frq[nums[i]]++;
        }
        return 0;
    }
};