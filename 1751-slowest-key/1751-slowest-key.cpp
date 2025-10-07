
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx=releaseTimes[0],n=releaseTimes.size();
        for(int i=1;i<n;++i)mx=max(mx,releaseTimes[i]-releaseTimes[i-1]);
        cout<<mx<<endl;
        string ans;
        if(mx==releaseTimes[0])
        ans+=(keysPressed[0]);

        for(int i=1;i<n;++i){
            if(releaseTimes[i]-releaseTimes[i-1]==mx){
                ans+=(keysPressed[i]);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
        return ans[ans.size()-1];
    }
};