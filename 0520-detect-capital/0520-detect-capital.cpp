class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(char c: word){
            cap+=(isupper(c)?1:0);
        }
        return (cap==word.size() or cap==0 or ( cap==1 and isupper(word[0])) );
    }
};