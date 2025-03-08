class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
        int mn=k;
        for(int i=0;i<n;++i){
            int w=0,b=0;
            for(int j=i;j<n;++j){
                w+=(s[j]=='W');
                b+=(s[j]=='B');
                if(j-i+1==k)mn=min(mn,max(k-b,0));
            }
        }
        return mn;
    }
};