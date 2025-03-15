class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), ans=0,left=0,right=0;
        vector<int>frq(300);
        while(left<n){
            while(right<n and (right-left)-*max_element(frq.begin(), frq.end())<=k )
                {frq[s[right++]]++;
                if((right-left)-*max_element(frq.begin(), frq.end())<=k)
            ans=max(ans,right-left);}
            cout<<left<<" "<<right<<endl;
            frq[s[left++]]--;
        }
        return ans;
    }
};
