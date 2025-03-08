class Solution {
public:
    int minimumRecolors(string s, int k) {
        vector<bool>v;
        for(auto&it:s){
            if(it=='B')v.push_back(1);
            else v.push_back(0);
        }
        int n=s.size(),sum=accumulate(v.begin(), v.begin()+k,0),mn=max(0,k-sum);
        for(int i=0;i+k<n;++i){
            sum-=v[i];
            sum+=v[i+k];
            mn=min(mn,max(0,k-sum));
        }
        return mn;
    }
};