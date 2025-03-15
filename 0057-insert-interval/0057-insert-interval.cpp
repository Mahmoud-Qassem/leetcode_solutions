class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;++i){
            int leftBound=intervals[i][0];
            if(leftBound<=ans.back()[1] ){
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>tmp;
        for(auto&it:intervals){
            int leftBound=it[0];
            if(newInterval[0]<=leftBound){
                tmp.push_back(newInterval);
                newInterval[0]=1001;
            }
            tmp.push_back(it);
        }
        if(newInterval[0]!=1001) tmp.push_back(newInterval);
        tmp=merge(tmp);
        return tmp;
    }
};