class Solution {
public:
    string clearDigits(string s) {
        int digit=0,n=s.size();
        string ans;
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                digit++;
            }
            else{
                if(digit)digit--;
                else ans=s[i]+ans;
            }
        }
        return ans;
    }
};