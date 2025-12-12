class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] leftMoves=new int[n]; 
        int[] pref=new int[n]; 
        int[] rightMoves=new int[n]; 
        int[] suff=new int[n];
        int moves=0;

        pref[0]=(boxes.charAt(0)=='1'?1:0);
        for(int i=1;i<n;++i){
            int box=(boxes.charAt(i)=='1'?1:0);
            int prev=pref[i-1];
            moves+=prev;
            leftMoves[i]=moves;
            pref[i]=box+prev;
        }
        suff[n-1]=(boxes.charAt(n-1)=='1'?1:0);
        moves=0;
        for(int i=n-2;i>=0;--i){
            int box=(boxes.charAt(i)=='1'?1:0);
            int prev=suff[i+1];
            moves+=prev;
            rightMoves[i]=moves;
            suff[i]=box+prev;
        }

        

        int ans[] = new int[n];
        ans[0]=rightMoves[0];
        ans[n-1]=leftMoves[n-1];
        for(int i=0;i<n;++i){
            ans[i]=leftMoves[i]+rightMoves[i];
        }
        return ans;
    }


}

/*
1 1 1 2 0 1
1 2 3 5 5 6
1 3 6 11


*/