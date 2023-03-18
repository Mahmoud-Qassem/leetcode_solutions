
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,deque<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;++i)
            mp[nums[i]].push_front(i);
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(nums[i]*2==target)
            {
                if(mp[ nums[i] ].size()>1)
                {
                    ans.push_back(mp[ nums[i] ].back());
                    mp[nums[i]].pop_back();

                    ans.push_back(mp[ nums[i] ].back());
                    mp[nums[i]].pop_back();
                }
            }
            else if(mp[ nums[i] ].size() and mp[ target-nums[i] ].size())
            {
                ans.push_back(mp[ nums[i] ].back());
                    mp[nums[i]].pop_back();
                ans.push_back(mp[ target-nums[i] ].back());
                    mp[ target-nums[i] ].pop_back();
            }
        }
        return ans;


    }
};