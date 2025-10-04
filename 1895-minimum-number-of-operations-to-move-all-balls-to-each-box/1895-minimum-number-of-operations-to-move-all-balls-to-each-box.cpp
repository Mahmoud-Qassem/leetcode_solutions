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
          vector<int>pref(n+2);
          vector<int>suff(n+2);
          if(boxes[0]=='1')pref[0]=1;
          
          for(int i=1;i<n;++i){
            int x = (boxes[i]=='1')?1:0;
            pref[i]+=pref[i-1]+x;
          }
          for(int i=1;i<n;++i){
            pref[i]+=pref[i-1];
          }
          
          if(boxes[n-1]=='1')suff[n-1]=1;
          
          for(int i=n-2;i>=0;--i){
            int x = (boxes[i]=='1')?1:0;
            suff[i]+=suff[i+1]+x;
          }
          
          for(int i=n-2;i>=0;--i){ 
            suff[i]+=suff[i+1];
          }
          operations[0]+=suff[1];
          for(int i=1;i<n;++i){
            operations[i]=(pref[i-1]+suff[i+1]);
          }
        
        return operations;
    }
};
