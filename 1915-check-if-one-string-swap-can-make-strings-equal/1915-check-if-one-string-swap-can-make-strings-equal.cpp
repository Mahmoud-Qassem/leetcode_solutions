class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int sz=s1.size();
        int sz2=s1.size();
        if(s1==s2)return true;
        for(int i=0;i<sz;++i){
            if(s1[i]!=s2[i])
            for(int j=0;j<sz;++j){
                swap(s1[i],s1[j]);
                if(s1==s2)return true;
                swap(s1[i],s1[j]);

            }
        }
        return false;
    }
};