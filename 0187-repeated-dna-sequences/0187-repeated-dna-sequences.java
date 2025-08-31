class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if(n < 10)return new ArrayList<>();
        /*
        HashSet properties
        add() :Returns true if this set did not already contain the specified element
        remove() :Returns true if this set contained the specified element
        contains() :Returns true if this set contains the specified element
        size() :Returns the number of elements in this set
        clear() :Returns void
        isEmpty() :Returns true if this set contains no elements

         */

        /*
        HashMap properties
        put() : Associates the specified value with the specified key in this map
        putIfAbsent() :If the specified key is not already associated with a value (or is mapped to null) associates it with the given value and returns null, else returns the current value

        get() : Returns the value to which the specified key is mapped, or null if this map contains no mapping for the key
        getOrDefault() :Returns the value to which the specified key is mapped, or defaultValue if this map contains no mapping for the key

        remove() :Removes the mapping for a key from this map if it is present

        containsKey() :Returns true if this map contains a mapping for the specified key
        containsValue() :Returns true if this map maps one or more keys to the specified value

        computeIfAbsent() :If the specified key is not already associated with a value (or is mapped to null) associates it with the given value computed by the given mapping function and returns the newly computed value
        ex: mp.computeIfAbsent(key, k -> 0);
        computeIfPresent() :If the specified key is already associated with a value associates it with the given value computed by the given mapping function and returns the newly computed value

        size() :Returns the number of key-value mappings in this map
        clear() :Removes all of the mappings from this map
        isEmpty() :Returns true if this map contains no key-value mappings
        keySet() :Returns a Set view of the keys contained in this map
        values() :Returns a Collection view of the values contained in this map
        entrySet() :Returns a Set view of the mappings contained in this map

         */

        Set<String> ans = new HashSet<>();
        Set<String> uniqueSets = new HashSet<>();


        for(int i=0;i<=n-10;++i){
            String sub = s.substring(i, i+10);
            if( ! uniqueSets.add(sub) ){
                ans.add(sub);
            }
            uniqueSets.add(sub);
        }
        return new ArrayList<>(ans);
    }
}