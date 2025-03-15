class Solution {
public:
    string minWindow(string big, string small) {
        int n=big.size(), m=small.size();
        if(n<m)return "";

        vector<int>crnt(128),fixed(128);
        for(char c:small)fixed[c]++;
        auto valid=[&]()-> bool{
            for(int i=0;i<128;++i){
                if(fixed[i] and fixed[i]>crnt[i]){
                    return false;
                }
            }
            return true;
        };
        int left=0,right=0,ans=INT_MAX,x=-1,y=-1;
        while(right<n){
            crnt[big[right]]++;
            right++;
            
            while(left<n and fixed[ big[left] ]< crnt[big[left]]){
                crnt[big[left]]--;
                left++;
            }
            if(valid()){
                if(ans>right-left+1){
                    x=left,y=right,ans=right-left+1;
                }
            }
        }
        if(x!=-1)return big.substr(x,y-x);
        return "";
    }
};