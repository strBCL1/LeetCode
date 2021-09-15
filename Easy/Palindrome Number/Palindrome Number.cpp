//Link to the puzzle: https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(const int& x) {
        if (x < 0) //If the number is negative - return false;
            return false;
        
        string stringNum = to_string(x); //Convert number to string to perform '2 pointers' traversal;
        
        for (int i = 0, j = stringNum.size() - 1; i < j; ++i, --j) {
            if (stringNum[i] != stringNum[j]) //If characters are different - return false;
                return false;
        }
        
        //If all characters match criteria - return true;
        return true;
    }
};
