
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx=releaseTimes[0],n=releaseTimes.size();
        for(int i=1;i<n;++i)mx=max(mx,releaseTimes[i]-releaseTimes[i-1]);
        set<char>ans;
        if(releaseTimes[0]==mx)
        ans.insert(keysPressed[0]);
        for(int i=1;i<n;++i){
            if(releaseTimes[i]-releaseTimes[i-1]==mx){
                ans.insert(keysPressed[i]);
            }
        }
        auto it=ans.end();
        it--;
        char c=*(it);
        return c;
    }
};