class Solution {
public:
     bool canConstruct(string ransomNote, string magazine) {
        int ransomFrq[26]={0};
        int magazineFrq[26]={0};

        for(char c:ransomNote)ransomFrq[c-'a']++;
        for(char c:magazine)magazineFrq[c-'a']++;

        for(int i=0;i<26;++i){
            if(magazineFrq[i]<ransomFrq[i])return false;
        }
        return true;
    }
};