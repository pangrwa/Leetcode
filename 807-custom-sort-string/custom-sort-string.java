class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character, Integer> count = new HashMap<>();
        StringBuilder res = new StringBuilder(); 

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);  
            count.put(c, count.getOrDefault(c, 0) + 1); 
        }

        for (int i = 0; i < order.length(); ++i) {
            char sortKey = order.charAt(i); 
            while (count.containsKey(sortKey)) {
                res.append(sortKey); 
                count.put(sortKey, count.get(sortKey) - 1);
                if (count.get(sortKey) == 0) {
                    count.remove(sortKey); 
                }
            }
        }
        
        // handle keys who did not appear in order
        for (Map.Entry<Character, Integer> set : count.entrySet()) {
            for (int i = 0; i < set.getValue(); ++i) {
                res.append(set.getKey()); 
            }
        }
        return res.toString(); 
    }
}

/*
counting sort? 
get the freq of s, build the new string based on the order
*/ 