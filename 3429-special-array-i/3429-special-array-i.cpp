class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool even=nums[0]%2;
        for(int i=0;i<nums.size();++i){
            if(i&1){
                if(nums[i]%2==even)return false;
            }
            else{
                if(nums[i]%2!=even)return false;
            }
        }
        return true;
    }
};