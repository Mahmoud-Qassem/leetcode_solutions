class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        vector<string>v;
        for(int i=0; i<20; ++i) {
            int msk=i;
            string tmp;
            while(msk) {
                if(msk%2)tmp='1'+tmp;
                else tmp='0'+tmp;
                msk/=2;
            }
            if(tmp.size()>n)break;
            int m=n-tmp.size();
            tmp=(string(m,'0')+tmp);
            v.push_back(tmp);
        }
        for(auto&it:v) {
            bool found=0;
            for(auto&ic:nums) {
                if(ic==it) {
                    found=1;
                    break;
                }
            }
            if(!found)return it;
        }
        return "000000";

    }
};