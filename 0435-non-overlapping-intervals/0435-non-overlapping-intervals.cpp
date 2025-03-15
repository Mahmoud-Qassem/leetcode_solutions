class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        //for(auto&it:intervals)it[0]+=200,it[1]+=200;

        //for(auto&it:intervals)cout<<"( "<<it[0]<<" , "<<it[1]<<" ) ,";cout<<endl;
        int mustBeRemoved=0, lastIdx=0;
        for(int i=1;i<n;++i){
            int crntLeftBound=intervals[i][0];
            int crntRightBound=intervals[i][1];
            // the relationship between every two consicative intervals 

            // 1- one contains another
            if(crntRightBound < intervals[lastIdx][1] ){
                mustBeRemoved++;
            }
            // 2- one intersect with the other
            else if(crntLeftBound < intervals[lastIdx][1] ){
                mustBeRemoved++;
                continue;
            }
            // 3- non intersection 
            lastIdx=i;
        }
        return mustBeRemoved;
        
    }
};