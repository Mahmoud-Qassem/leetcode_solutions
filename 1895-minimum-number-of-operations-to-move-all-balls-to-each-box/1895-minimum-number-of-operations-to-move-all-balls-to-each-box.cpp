class Solution {
public:
    vector<int> minOperations(string boxes) {
        // brute force approach
        int n= boxes.size();
        vector<int>operations(n);
        for(int i=0;i<n;++i){
            int minMoves=0;
            for(int j=0;j<n;++j){
                if(i==j)continue;
                if(boxes[j]=='1'){
                    minMoves+=(abs(i-j));
                }
            }
            operations[i]=minMoves;
        }
        return operations;
    }
};