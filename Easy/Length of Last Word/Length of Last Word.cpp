//Link to the puzzle: https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string& s) {
        while (s.back() == ' ') //Erase all spaces from the string end;
            s.pop_back();
        
        auto lastSpace = s.find_last_of(' '); //Get position of last space;
        if (lastSpace == string::npos) //If the space is absent in string, return its size (because the string contains only 1 word then);
            return s.size();
        else //Else return calculated size of last word;
            return s.size() - lastSpace - 1;
    }
};
