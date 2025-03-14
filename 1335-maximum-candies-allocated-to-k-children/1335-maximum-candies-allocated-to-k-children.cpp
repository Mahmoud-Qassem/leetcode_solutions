class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        long long mn=*min_element(candies.begin(),candies.end());
        long long left=1, right=sum/k,mid,n=candies.size(), ans=0;

        while(left<=right){
            mid=left+(right-left)/2;
            long long tmp=k;
            for(int i=0;i<n and tmp>0;++i){
                tmp-=(candies[i]/mid);
            }
            if(tmp<=0){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;

        }
        return ans;

        return min(mn,sum/k);
        
    }
};