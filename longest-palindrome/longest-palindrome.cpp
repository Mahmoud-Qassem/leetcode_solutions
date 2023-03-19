class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        int ans=0;
        vector<int>freq(300),odd,even;
        for(int i=0;i<n;++i)
        freq[s[i]]++;

        for(auto&it:freq)if(it&1)odd.push_back(it);else even.push_back(it);
        for(auto&it:even)ans+=it;
        sort(odd.begin(),odd.end());
        if(odd.size())ans+=odd[odd.size()-1];

        for(int i=0;i<int(odd.size())-1;++i)ans+=(odd[i]-1);
        return ans;
    }
};