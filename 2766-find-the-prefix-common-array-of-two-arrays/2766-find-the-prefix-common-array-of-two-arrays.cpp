class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int mp[100], n= A.size();
        int common=0;
        vector<int>ans(n);

        for(int i=0;i<n;++i){
            if(mp[A[i]])common++;
            mp[ A[i] ]++;
            if(mp[B[i]])common++;
            mp[ B[i] ]++;
            ans[i]=common;
        }

        return ans;
    }
};