class Solution {
    public List<String> res = new ArrayList<String>(); 
    public Stack<String> path = new Stack<>(); 

    public List<String> generateParenthesis(int n) {
        backTrack(n, n);
        return res; 
    }

    public void backTrack(int numOpen, int numClose) {
        if (numOpen < 0 || numClose < 0) {
            return; 
        }
        if (numOpen == 0 && numClose == 0) {
            String aPath = buildPath(); 
            res.add(aPath); 
        }
        if (numOpen > 0) {
            path.add("(");
            backTrack(numOpen - 1, numClose);
            path.pop(); 
        }
        if (numClose > 0 && numClose > numOpen) { // allows for opening
            path.add(")");
            backTrack(numOpen, numClose - 1);
            path.pop(); 
        }
        return; 
    }

    public String buildPath() {
        List<String> temp = new ArrayList<>(); 
        temp.addAll(path);
         String res = "";
         for (String i : temp) {
            res += i; 
         }
         return res; 
    }
}