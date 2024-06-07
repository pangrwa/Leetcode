class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        String[] wordArray = sentence.split(" "); 
        Set<String> dictSet = new HashSet<>(dictionary); 
        
        for (int i = 0; i < wordArray.length; ++i) {
            wordArray[i] = shortestRoot(wordArray[i], dictSet); 
        }

        return String.join(" ", wordArray); 
    }

    public String shortestRoot(String word, Set<String> dict) {
        StringBuilder temp = new StringBuilder(); 
        for (int i = 0; i < word.length(); ++i) {
            temp.append(word.charAt(i));
            if (dict.contains(temp.toString())) {
                return temp.toString();
            }
        }
        return temp.toString(); 
    }
}