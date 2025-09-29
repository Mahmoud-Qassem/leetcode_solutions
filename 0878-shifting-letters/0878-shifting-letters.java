class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n= shifts.length;
        for(int i=n-2;i>=0;i--){
            shifts[i]+=shifts[i+1];
            shifts[i]%=26;
        }
        char[] ch = s.toCharArray();
        for(int i=0;i<n;++i){
            int x = (shifts[i] + ch[i]-97)%26 ;
            ch[i] = (char)(x+97);
        }
        return new String(ch);
    }
}