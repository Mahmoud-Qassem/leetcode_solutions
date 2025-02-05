class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factors;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                int x=i;
                int y=n/i;
                factors.push_back(x);
                if(y>sqrt(n))
                factors.push_back(y);
            }
        }
        if(k>factors.size())return -1;
        sort(factors.begin(), factors.end());
        return factors[k-1];
    }
};