class Solution {
public:
    int partitionString(string s) {
        s+=s.back();
        int n=s.size(),cnt=0;
        vector<int>frq(27);
        for(int i=0;i<n;++i){
            if(frq[s[i]-'a']){
                cnt++;
                frq=vector<int>(27);
            }
            frq[s[i]-'a']++;
        }
        return cnt;
    }
};