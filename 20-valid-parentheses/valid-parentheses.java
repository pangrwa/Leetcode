class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (isOpen(c)) {
                stack.push(c); 
            } else { // close
                if (stack.empty()) {
                    return false;
                }
                if (!matching(stack.peek(), c)) {
                    return false; 
                }
                stack.pop(); 
            }
        }
        return stack.empty(); 
    }

    public boolean isOpen(char c) {
        return (c == '(') || (c == '{') || (c == '['); 
    }

    public boolean matching(char a, char b) {
        return (
            (a == '(' && b == ')') || 
            (a == '[' && b == ']') ||
            (a == '{' && b == '}')
        );
    }
}