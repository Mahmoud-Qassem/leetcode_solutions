class Solution {
public:
    string minWindow(string big, string small) {
        int n=big.size(), m=small.size();
        if(n<m)return "";

        vector<int>crnt(300),fixed(300);
        for(char c:small)fixed[c]++;

        auto notyet=[&]()-> bool{
            for(int i=0;i<300;++i){
                if(fixed[i] and fixed[i]>crnt[i]){
                    return true;
                }
            }
            return false;
        };
        auto valid=[&]()-> bool{
            for(int i=0;i<300;++i){
                if(fixed[i] and fixed[i]>crnt[i]){
                    return false;
                }
            }
            return true;
        };
        int left=0,right=0,ans=INT_MAX,x=-1,y=-1;
        while(left<n){
            while(right<n and notyet()){
                crnt[big[right]]++;
                right++;
            }
            if(valid()){
                //cout<<left<<" "<<right<<endl;
                if(ans>right-left+1){
                    x=left,y=right,ans=right-left+1;
                }
            }
            crnt[big[left]]--;
            left++;
        }
        if(x!=-1)return big.substr(x,y-x);
        return "";
    }
};