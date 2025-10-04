class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int>mp;int ans=0;
        for(string word:words){
            ans+=mp[word];
            reverse(word.begin(),word.end());
            mp[word]++;
        }   
        return ans;
    }
};