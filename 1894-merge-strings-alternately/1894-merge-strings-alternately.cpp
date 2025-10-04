class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left=0,right=0;
        int n=word1.size();
        int m=word2.size();
        string ans;
        while(left<n and right<m){
            ans+=word1[left++];
            ans+=word2[right++];
        }
        
        while(left<n){
            ans+=word1[left++];
        }
        
        while(right<m){
            ans+=word2[right++];
        }
        return ans;
    }
};