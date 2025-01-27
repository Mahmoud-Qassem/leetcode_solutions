#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;++i){
            v[i]={nums[i],i};
        }
        sort(all(v));
        int left=0,right=1;
        set<int>idxs;
        idxs.insert(v[0].second);
        while(left<n){
            while(right<n and v[right].first-v[right-1].first<=limit){
                idxs.insert(v[right].second);
                right++;
            }
            int i=left;
            for(auto&it:idxs){
                nums[it]=v[i++].first;
            }
            idxs.clear();
            
            left=right;
            right++;
            if(left<n)
            idxs.insert(v[left].second);
        }
        return nums;

    }
};