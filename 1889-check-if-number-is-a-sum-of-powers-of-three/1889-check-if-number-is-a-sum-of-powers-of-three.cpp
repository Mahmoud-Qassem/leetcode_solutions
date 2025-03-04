class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=15;i>=0;--i){
            int p=(int)(pow(3,i));
            if(p<=n){
                n-=p;
            }
        }
        return !n;
    }
};