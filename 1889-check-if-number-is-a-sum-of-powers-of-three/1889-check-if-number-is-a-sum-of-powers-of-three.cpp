class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=0;
        int mx=1e7+500;
        while(mx){
            mx/=3;
            x++;
        }
        for(int i=x;i>=0;--i){
            int p=(int)(pow(3,i));
            if(p<=n){
                n-=p;
            }
        }
        return !n;
    }
};