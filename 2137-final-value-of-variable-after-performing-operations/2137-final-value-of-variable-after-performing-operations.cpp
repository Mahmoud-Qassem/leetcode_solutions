class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto&op:operations){
            if(op[0]=='+' or op[2]=='+')x++;
            else x--;
        }
        return x;
    }
};