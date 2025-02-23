class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int>nxtBigger;
        int n=v.size();
        vector<int>ans(n);
        ans[n-1]=0;
        nxtBigger.push(n-1);
        for(int i=n-2;i>=0;--i){
            while(nxtBigger.size() and v[ nxtBigger.top() ]<=v[i]){
                nxtBigger.pop();
            }
            if(nxtBigger.size())ans[i]=nxtBigger.top()-i;
            nxtBigger.push(i);
        }
        return ans;

    }
};