class Solution {
public:
    set<string>mine;
    int x;
    void rec(string crnt){
        if(crnt.size()==x){
            mine.insert(crnt);
            return ;
        }
        
        char last='M';
        if(crnt.size())
            last=crnt.back();
            
        if(last=='a'){
            rec(crnt+'c');
            rec(crnt+'b');
            
        }
        else if(last=='b'){
            rec(crnt+'c');
            rec(crnt+'a');
        }
        else if(last=='c'){
            rec(crnt+'b');
            rec(crnt+'a');
        }
        else{            
            rec(crnt+'a');
            rec(crnt+'b');
            rec(crnt+'c');
        }
    }
    string getHappyString(int n, int k) {
        mine.clear();
        x=n;
        rec("");
        //if(mine.size()<k)return "";
        for(auto&it:mine){
            k--;
            if(not k)return it;
        }
        return "";
    }
};