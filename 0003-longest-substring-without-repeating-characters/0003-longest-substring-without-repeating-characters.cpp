class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,left=0,right=0,n=s.size();
        vector<int>frq(555);
        while(left<n){
            while(right<n and !frq[s[right]])
                frq[s[right++]]++;

            ans=max(ans,right-left);
            frq[s[left++]]--;
        }
        return ans;
    }
};
