class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        bool A[101]={false};
        bool B[101]={false};
        for(auto x:nums1)A[x]=true;

        int ans1=0, ans2=0;
        for(auto x:nums2){
            if(A[x])ans1++;
            B[x]=1;
        }
        for(auto x:nums1){
            if(B[x])ans2++;
        }
        return {ans2, ans1};

        
    }
};