class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if(n < 10)return new ArrayList<>();
        HashSet<String> ans = new HashSet<>();
        HashSet<String> uniqueSets = new HashSet<>();


        for(int i=0;i<=n-10;++i){
            String sub = s.substring(i, i+10);
            if( ! uniqueSets.add(sub) ){
                ans.add(sub);
            }
            //uniqueSets.add(sub);
        }
        return new ArrayList<>(ans);
    }
}