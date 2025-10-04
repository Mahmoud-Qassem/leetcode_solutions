class Solution {
public:
    bool judgeCircle(string s) {
        int up=0, left=0, n= s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='U')up++;
            else if (s[i]=='D')up--;

            if(s[i]=='L')left++;
            else if (s[i]=='R')left--;
        }
        return !(up|left);
    }
};