class Solution {
public:
    int a = 0;
    void c(vector<int>&f){
        for(int i = 0;i<26;i++){
            if(f[i]>0){
                f[i]--;
                a++;
                c(f);
                f[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>f(26,0);
        for(auto ch : tiles)f[ch -'A']++;
        c(f);
        return a;
    }
};