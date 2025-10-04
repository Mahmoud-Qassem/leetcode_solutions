class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0,n=nums.size();
        int last=-10001, lastCnt=0, k=0;

        for(int i=0;i<n;++i){
            if(nums[i]==last){
                if(lastCnt<2){
                    lastCnt++;
                    nums[left++]=last;
                    k++;
                }
            }
            else{
                last=nums[i];
                lastCnt=1;
                nums[left++]=last;
                    k++;
            }
        }
        return k;
    }
};