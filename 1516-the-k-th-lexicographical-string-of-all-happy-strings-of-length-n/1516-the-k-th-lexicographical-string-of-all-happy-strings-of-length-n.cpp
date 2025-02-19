class Solution {
public:
    string ans="";
    void rec(int n,string crnt,int&k){
        if(!k)return ;
        if(crnt.size()==n){
            k--;
            if(not k)ans=crnt;
            return ;
        }
        
        char last='M';
        if(crnt.size())
            last=crnt.back();
            
        if(last=='a'){
            rec(n,crnt+'b',k);
            rec(n,crnt+'c',k);            
        }
        else if(last=='b'){
            rec(n,crnt+'a',k);            
            rec(n,crnt+'c',k);            
        }
        else if(last=='c'){
            rec(n,crnt+'a',k);            
            rec(n,crnt+'b',k);                        
        }
        else{            
            rec(n,crnt+'a',k);            
            rec(n,crnt+'b',k);            
            rec(n,crnt+'c',k);            
        }
    }
    string getHappyString(int n, int k) {
        ans="";
        rec(n,"",k);
        return ans;
    }
};