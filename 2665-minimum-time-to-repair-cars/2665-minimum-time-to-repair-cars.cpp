class Solution {
    bool valid(long long  mid, vector<int>& ranks, int cars){
        
        for(auto&it:ranks){
            long long sq=sqrt(mid/it);
            cars-=sq;
            if(cars<=0)return true;
        }
        
        return (cars<=0);
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long  left=0, right=1e14+5,ans=0;
        
        while(left<=right){
            long long mid= left+(right-left)/2;
            if(valid(mid,ranks,cars)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};