class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=15;
        while(x--){
            int p=(int)(pow(3,x));
            if(p<=n){
                n-=p;
            }
        }
        return !n;
    }
};