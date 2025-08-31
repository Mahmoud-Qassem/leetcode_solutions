class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if(n < 10)return new ArrayList<>();


        List<String> ans = new ArrayList<>();
        Map<String, Integer> mp = new HashMap<>();

        for(int i=0;i<=n-10;++i){
            String sub = s.substring(i, i+10);
            //System.out.println(sub);
            mp.put(sub, mp.getOrDefault(sub, 0) + 1);
        }
        for(var e: mp.entrySet()){
            String Key = e.getKey();
            int Value = e.getValue();

            if(Value > 1)ans.add(Key);
        }
        return ans;
    }
}