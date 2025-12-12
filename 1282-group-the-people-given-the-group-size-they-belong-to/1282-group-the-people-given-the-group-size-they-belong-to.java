class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < groupSizes.length; i++) {
            int size = groupSizes[i];
            
            mp.putIfAbsent(size, new ArrayList<>());
            mp.get(size).add(i);

            // If the group is full
            if (mp.get(size).size() == size) {
                ans.add(new ArrayList<>(mp.get(size))); // copy
                mp.get(size).clear(); // reset
            }
        }
        return ans;
    }
}
