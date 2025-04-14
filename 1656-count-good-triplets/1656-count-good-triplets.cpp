class Solution {
public:
    int countGoodTriplets(vector<int>& v, int a, int b, int c) {
        int n=v.size(),ans=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(int k=j+1;k<n;++k){
                    if(abs(v[i]-v[j]) <=a and abs(v[i]-v[k]) <=c and abs(v[k]-v[j]) <=b )ans++;
                }
            }
        }
        return ans;
    }
};