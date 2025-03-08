class Solution {
public:
    int minimumRecolors(string s, int k) {
        int left=0,right=0,w=0,b=0,n=s.size();
        while(right-left+1<=k){
            w+=(s[right]=='W');
            b+=(s[right]=='B');
            right++;
        }
        int mn=max(k-b,0);
        cout<<mn<<endl;
        while(right<n){
            w-=(s[left]=='W');
            b-=(s[left]=='B');
            left++;
            w+=(s[right]=='W');
            b+=(s[right]=='B');
            if(right-left+1==k)
            mn=min(mn,max(k-b,0));
            right++;
            cout<<mn<<endl;
        }
        return mn;
    }
};