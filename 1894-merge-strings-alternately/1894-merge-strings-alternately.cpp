class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int left=0,right=0,n=word1.size(),m=word2.size(),turn=1;
        while(right<n and right<m){
            if(turn)res+=word1[left++];
            else res+=word2[right++];
            turn^=1;
        }
        while(left<n)res+=word1[left++];
        while(right<m)res+=word2[right++];
        return res;
    }
};