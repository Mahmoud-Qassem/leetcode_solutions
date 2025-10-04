class Solution {
public:
    vector<int> partitionLabels(string s) {
        set<int>st;
        int mp[26]={0};
        int n=s.size();
        
        for(int i=n-1;i>=0;--i){
            mp[ s[i]-'a' ]++;
        }


        vector<int>ans;
        int left=0;
        for(int i=0;i<n;++i){
            mp[s[i]-'a']--;
            st.insert( s[i]-'a' );

            bool NoRemainingOfAllPrevLetters=true;
            for(auto it=st.begin();it!=st.end();it++){
                int c=(*it);
                if(mp[c]){
                    NoRemainingOfAllPrevLetters=false;
                    break;
                }
            }

            if(NoRemainingOfAllPrevLetters){
                ans.push_back(i-left+1);
                left=i+1;
            }
        }
        return ans;
    }
};