class Solution {
public:
    int minSteps(string s, string t) {
        int aFrq[26], bFrq[26], ans=0;
        for(char c:s)aFrq[c-'a']++;
        for(char c:t)bFrq[c-'a']++;
        
        for(int i=0;i<26;++i){
            ans+=abs(aFrq[i]-bFrq[i]);
        }
        return ans/2;
        
    }
};