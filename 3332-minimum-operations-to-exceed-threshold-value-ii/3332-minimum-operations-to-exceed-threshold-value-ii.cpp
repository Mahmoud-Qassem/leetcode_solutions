#pragma GCC optimize("O3,inline")
#pragma GCC target("sse2,sse3,sse4.1,sse4.2,avx,avx2,popcnt,fma,bmi,bmi2,lzcnt")
#pragma clang attribute push ([[gnu::target("sse2,sse3,sse4.1,sse4.2,avx,avx2,popcnt,fma,bmi,bmi2,lzcnt")]], apply_to=function)
#include <ranges>
namespace {
    const int _ = []{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
}
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ops=0;
        multiset<long long>s;
        for(long long it:nums) {
            if(it<k)
            s.insert(it);
        }
        if(s.empty())return 0;

        auto x=s.begin();
        while(s.size()>1) {
            long long s1=*(x);
            s.erase(x);
            x=s.begin();
            long long s2=*(x);
            s.erase(x);

            s.insert(s1*2+s2);
            ops++;
            x=s.begin();
            if(*x>=k)break;
        }
        if(*x<k)ops++;
        return ops;
    }
};
#pragma clang attribute pop