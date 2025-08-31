class Solution {
    public int reverse(int x) {
        long reversedInt =0;
        int ab = Math.abs(x);
        while(ab>0){
            int digit = ab%10;
            reversedInt*=10;
            reversedInt+=digit;
            System.out.println(reversedInt);
            ab/=10;
        }
        if(x<0)reversedInt*=-1;
        if(reversedInt> Integer.MAX_VALUE || reversedInt < Integer.MIN_VALUE) return 0;
        return (int)reversedInt;
    }
}