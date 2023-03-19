class Solution {
public:
    bool isSubsequence(string s, string t) {

        int ss=s.size()    ,idx=0,     tt=t.size();
        if(ss>tt)return 0;
            for(int j=0;j<tt and idx<ss;++j)
            {
                if(t[j]==s[idx])
                {
                    idx++;
                }
            }
        if(idx==ss)return true;
        return false;
    }
};