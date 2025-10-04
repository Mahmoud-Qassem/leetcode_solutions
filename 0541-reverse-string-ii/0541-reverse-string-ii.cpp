class Solution {
public:
    string reverseStr(string s, int k) {
       int n = s.size();
        for(int i=0;i<n;i+=2*k){
            int left =i, right= min(i+k-1, n-1), sz = right-left+1;
            for(int j=left;j<=left+(right-left)/2;++j){
                swap(s[j], s[right-j+left]);
            }
        }
        return s; 
    }
};