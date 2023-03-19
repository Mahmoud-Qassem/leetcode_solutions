
class Solution {
public:
    int firstBadVersion(int n) {
        long long left=0,right=n;
        long long ans,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(isBadVersion(mid)){ans=mid;right=mid-1;}
            else left=mid+1;
        }
        return ans;
    }
};