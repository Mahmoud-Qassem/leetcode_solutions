class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>tmp;
        int n=nums.size();
        for(int i =0;i<n;++i){
            tmp.push_back({nums[i], i});
        }
        sort(tmp.begin(),tmp.end());
        
        int left=0,right=nums.size()-1;
        while(left<right){
            if(tmp[left].first+tmp[right].first<target)left++;
            else if(tmp[left].first+tmp[right].first>target)right--;
            else return {tmp[left].second,tmp[right].second};
        }

        return {1111111111};
    }
};