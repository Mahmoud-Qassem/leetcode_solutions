class Solution {
public:
    int punishmentNumber(int n) {
        int sum=0;
        auto check=[&](int i)-> bool{
            string s=to_string(i*i);
            int sz=s.size();
            for(int msk=0,tmp,crnt=0;msk<(1<<sz);++msk,crnt=0){
                tmp=msk;
                bool lst=tmp%2;
                string sub;
                
                for(int j=0;j<sz;++j,lst=tmp%2,tmp/=2){
                    if(tmp%2==lst){
                        sub+=s[j];
                    }
                    else{
                        crnt+=stoi(sub);
                        sub="";
                        sub+=s[j];
                    }
                    if(j==sz-1)
                        crnt+=stoi(sub);
                }
                if(crnt==i)return 1;
            }
            return 0;
            
        };
        
        for(int i=1;i<=n;++i){
            if(check(i))sum+=i*i;
        }
        return sum;
    }
};