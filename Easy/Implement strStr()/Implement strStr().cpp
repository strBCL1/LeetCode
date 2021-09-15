//Link to the puzzle: https://leetcode.com/problems/implement-strstr
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto needlePos = haystack.find(needle);
        return needlePos == string::npos ? -1 : needlePos;
    }
};
