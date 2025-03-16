class Solution {
    bool valid(long long  mid, vector<int>& ranks, int cars){
        
        for(auto&it:ranks){
            long long tmp=mid/it;
            long long sq=sqrt(tmp);
            
            //if(sq*sq!=mid)return false;
            cars-=sq;
            if(cars<=0)return true;
        }
        
        return (cars<=0);
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long  left=0, right=1e18,ans=0;
        
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