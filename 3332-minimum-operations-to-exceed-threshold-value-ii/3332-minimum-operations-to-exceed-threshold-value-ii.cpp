class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ops=0,n=nums.size();
        multiset<long long>s;
        for(long long it:nums) {
            s.insert(it);
        }

        auto x=s.begin();
        while(s.size()>1 and *x<k) {
            long long s1=*(x);
            s.erase(x);
            x=s.begin();
            long long s2=*(x);
            s.erase(x);

            s.insert(s1*2+s2);
            ops++;
            x=s.begin();
        }
        return ops;
    }
};