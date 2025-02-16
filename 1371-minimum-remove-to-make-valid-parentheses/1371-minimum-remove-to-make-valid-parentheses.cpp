class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0, n=s.size(),cnt=0;
        vector<bool>ok(n,1);
        for(int i=0;i<n;++i){
            if(s[i]=='(')open++;
            else if(s[i]==')')open--;
            if(open<0){
                cnt++,open=0;
                ok[i]=0;
            }
        }
        cnt+=open;
        for(int i=n-1;i>=0 and open;--i){
            if(s[i]=='(')ok[i]=0,open--;
        }

        cout<<cnt<<endl;
        string ans;
        for(int i=0;i<n;++i){
            if(ok[i])ans+=s[i];
        }
        return ans;
    }
};