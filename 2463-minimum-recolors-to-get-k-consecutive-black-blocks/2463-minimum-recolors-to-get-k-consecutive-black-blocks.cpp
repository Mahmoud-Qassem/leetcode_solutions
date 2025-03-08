class Solution {
public:
    int minimumRecolors(string s, int k) {
        vector<bool>v;
        for(auto&it:s){
            if(it=='B')v.push_back(1);
            else v.push_back(0);
        }
        int n=s.size(),mn=k,sum=0;
        for(int i=0;i+k-1<n;++i){
            sum=accumulate(v.begin()+i, v.begin()+k+i,0);
            mn=min(mn,max(0,k-sum));
        }
        return mn;
    }
};