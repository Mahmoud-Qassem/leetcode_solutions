class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>indices;
        int idx=0;

        for(auto word: words){
            int n= word.size();
            if(word.find(x)!= std::string::npos){
                indices.push_back(idx);
            }
            idx++;
        }
        
        return indices;
    }
};