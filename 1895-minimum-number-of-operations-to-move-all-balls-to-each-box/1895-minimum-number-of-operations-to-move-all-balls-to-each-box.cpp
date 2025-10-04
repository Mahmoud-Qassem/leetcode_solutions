class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector<int>operations(n);
        
//        // brute force approach
//        for(int i=0;i<n;++i){
//            int minMoves=0;
//            for(int j=0;j<n;++j){
//                if(i==j)continue;
//                if(boxes[j]=='1'){
//                    minMoves+=(abs(i-j));
//                }
//            }
//            operations[i]=minMoves;
//        }


          // optimized approach
        int prefSum=0, doublePrefSum=0;
        int suffixSum=0, doubleSuffixSum=0;
        for(int i=0;i<n;++i){
            // do the prefix sum
            operations[i]+=doublePrefSum;
            prefSum+=boxes[i]-'0';
            doublePrefSum +=prefSum; 
            // do the suffix fum
            
            int j=n-i-1;
            operations[j]+=doubleSuffixSum;
            suffixSum+=boxes[j]-'0';
            doubleSuffixSum +=suffixSum;
        }

        return operations;
    }
};
