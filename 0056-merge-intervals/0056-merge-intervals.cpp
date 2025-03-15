class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;++i){
            int leftBound=intervals[i][0];
            if(leftBound<=ans.back()[1] ){
                ans.back()[0]=min(intervals[i][0],ans.back()[0]);
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
            else ans.push_back({intervals[i][0],intervals[i][1]});
        }
        return ans;
    }
};