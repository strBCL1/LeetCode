//Link to the puzzle: https://leetcode.com/problems/valid-parentheses
class Solution {
public:
    bool isValid(string& s) {
        stack<char> st; //Declare stack to store parantheses;
        
        //For each paranthesis in string:
        for (const char& c : s) {
            //If stack isn't empty and its top paranthesis is a pair to current paranthesis --> erase top paranthesis from stack;
            //Else push current paranthesis to stack;
            if (!st.empty() && 
               ( (c == ']' && st.top() == '[') ||
                 (c == ')' && st.top() == '(') ||
                 (c == '}' && st.top() == '{')) )
                st.pop();
            else 
                st.push(c);
        }
        
        //If stack is empty, it means each paranthesis has its pair in string, so the stack would always be empty;
        return st.empty();
    }
};
