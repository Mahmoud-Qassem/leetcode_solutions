class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        if (s.length() <= 10 || s.length() >= 100000)
            return new ArrayList<String>();
        HashSet<String> uniqueSets = new HashSet<>();
        HashSet<String> result = new HashSet<>();

        for (int i = 0; i < s.length() - 9; i++) {
            var key = s.substring(i, i + 10);
            if (!uniqueSets.add(key)) {
                result.add(key);
            }
        }

        return new ArrayList<>(result);
    }
}