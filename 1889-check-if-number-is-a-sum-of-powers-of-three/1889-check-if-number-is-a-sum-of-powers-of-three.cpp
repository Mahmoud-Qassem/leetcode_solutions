class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=16;
        for(int i=x;i>=0;--i){
            int p=(int)(pow(3,i));
            if(p<=n){
                n-=p;
            }
        }
        return !n;
    }
};