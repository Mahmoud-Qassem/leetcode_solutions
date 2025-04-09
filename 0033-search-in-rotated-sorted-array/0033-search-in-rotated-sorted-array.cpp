
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1)return nums[0]==target?0:-1;
        if(n==2)return nums[0]==target?0:nums[1]==target?1:-1;
        bool rotated=nums[0]>=nums[n-1];
        auto bs=[&](int start, int end)->int{
            int left=start, right=end;
            while(left<=right) {
                int mid=left+right>>1;
                if(nums[mid]>target)right=mid-1;
                else if (nums[mid]<target)left=mid+1;
                else return mid;
            }
            return -1;
        };

        if(not rotated) {
            return bs(0,n-1);
        } else {
            int pivot=0;
            int left=0,right=n-1;
            while(left<=right) {
                int mid=left+right>>1;
                if(mid>0 and mid<n-1) {
                    if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]) {
                        pivot=mid+1;
                        break;
                    }
                    if(nums[mid]<nums[mid+1] and nums[mid]<nums[mid-1]) {
                        pivot=mid;
                        break;
                    }
                }                     
                if(nums[mid]>=nums[0])left=mid+1;
                else right=mid-1;
                
            }
            int leftSeg=bs(0,pivot-1);
            int rightSeg=bs(pivot,n-1);
            return (leftSeg!=-1?leftSeg:rightSeg);
        }
        return 0;
    }
};
