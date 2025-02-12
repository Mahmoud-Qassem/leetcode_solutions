class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<multiset<int>>mp(200);
        int ans=-1;
        for(auto&it:nums){
            int digit_sum=0;
            int tmp=it;
            while(tmp){
                digit_sum+=tmp%10;
                tmp/=10;
            }
            //cout<<it<<" "<<digit_sum<<endl;
            mp[digit_sum].insert(it);

            if(mp[digit_sum].size()>1){
                auto cof=mp[digit_sum].end();
                int first=*(--cof);
                int second=*(--cof);
                //cout<<digit_sum<<' '<<first<<" "<<second<<endl;
                ans=max({ans,first+second});
            }
        }
        return ans;
    }
};