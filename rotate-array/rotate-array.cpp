#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>q;
        for(int i=0;i<nums.size();++i)
        q.push_back(nums[i]);
        for(int i=0;i<k;++i)
        {
            int tmp=q.back();
            q.pop_back();
            q.push_front(tmp);
        }
        for(int i=0;i<nums.size();++i)
        nums[i]=q[i];
 
    }
};