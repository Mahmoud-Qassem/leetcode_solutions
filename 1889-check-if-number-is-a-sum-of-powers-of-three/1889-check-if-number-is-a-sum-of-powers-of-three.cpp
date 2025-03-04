class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=15;
        while(x--){
            if((int)(pow(3,x))<=n){
                n-=(int)(pow(3,x));
            }
        }
        return !n;
    }
};