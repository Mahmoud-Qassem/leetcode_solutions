class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        long[] longShifts = new long[shifts.length];
        longShifts[shifts.length-1] = shifts[shifts.length-1];
        int n= shifts.length;
        for(int i=n-2;i>=0;i--){
            longShifts[i] = longShifts[i+1] + shifts[i];
        }
        char[] ch = s.toCharArray();
        for(int i=0;i<n;++i){
            long x = (longShifts[i] + ch[i]-97)%26 ;
            ch[i] = (char)(x+97);
        }
        return new String(ch);
    }
}