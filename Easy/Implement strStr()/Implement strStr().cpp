class Solution {
public:
    int strStr(string haystack, string needle) {
        auto needlePos = haystack.find(needle);
        return needlePos == string::npos ? -1 : needlePos;
    }
};
