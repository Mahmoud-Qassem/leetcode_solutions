class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=upper_bound(nums.begin(),nums.end(),-1)-nums.begin();
        int pos=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        //cout<<neg<<" "<<nums.size()-neg<<endl;
        return max (neg, (int)nums.size()-pos);
    }
};