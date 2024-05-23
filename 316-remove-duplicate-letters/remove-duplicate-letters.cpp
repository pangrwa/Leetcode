class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq; 
        for (char c : s) {
            freq[c]++; 
        }
        stack<char> incrStack;
        unordered_set<char> built;  
        for (char c : s) {
            // if built already contains the possibly small element c
            // then its already in the good place
            if (!built.contains(c)) { 
                while (
                    !incrStack.empty() &&
                    incrStack.top() >= c &&
                    freq[incrStack.top()] > 0
                ) {
                    char top = incrStack.top();
                    incrStack.pop();
                    built.erase(top);
                }
                incrStack.push(c);
                built.insert(c); 
            }
            freq[c]--; 
        }

        string res = ""; 
        while (!incrStack.empty()) {
            res = incrStack.top() + res; 
            incrStack.pop(); 
        }
        return res; 
    }
};

/*
how to ensure duplicate letters appear once only? 
- create a set that tracks the string?
how to ensure smallest lexigraphical order
- greedily form a string in this order if possible ab...z
- create an increasing stack that will represent the new string
- will trying to push a new char into the new string, if the char
    is lexicograpiaclly bigger, remove the char only if we 
    know there exists another char later
*/ 