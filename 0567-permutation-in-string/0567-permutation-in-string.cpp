class Solution {
public:
    bool checkInclusion(string small, string big) {
        int n=big.size(), m=small.size();
        if(n<m)return false;

        vector<int>fr(26),fixed(26);
        for(char c:small)fixed[c-'a']++;

        auto maybe=[&]()-> bool{
            for(int i=0;i<26;++i){
                if(fixed[i] and fixed[i]>fr[i]){
                    return true;
                }
            }
            return false;
        };
        int left=0,right=0;
        while(left<n){
            while(right<n and maybe()){
                fr[big[right]-'a' ]++;
                right++;
            }
            //cout<<left<<" "<<right<<endl;
            if(fr==fixed)return true;

            fr[big[left++] -'a']--;
        }
        return false;

    }
};
