class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        auto divide = [&](string gcd)->bool{
            bool ok=1;
            int x=gcd.size(),i=0;
            for(i=0;i+x<=n;i+=x){
                string tmp=str1.substr(i,x);
                //cout<<tmp<<" "<<gcd<<endl;
                if(tmp!=gcd)return 0;
            }
            if(i!=n)return 0;
            
            for(i=0;i+x<=m;i+=x){
                string tmp=str2.substr(i,x);
                //cout<<tmp<<" "<<gcd<<endl;
                if(tmp!=gcd)return 0;
            }
            if(i!=m)return 0;
            return 1;
        };
        string s,ans="";
        for(auto c:str1){
            s+=c;
            if(divide(s))ans=s;
        }
        return ans;
    }
};