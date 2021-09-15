class Solution {
public:
    //Function to get int value from roman character;
    int romValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
        }
                
        return 1000;
    }
    
    int romanToInt(string s) {
        int sum = 0; //Initialize total sum var;
        
        //From right to left:
        for (int i = s.size() - 1; i >= 0; --i) {
            //If value of current character is lesser than value of previous character (to the right) --> subtract value of current character from sum (IX = 9, XI = 11);
            //Else add current character value to sum;
            sum += (romValue(s[i]) < romValue(s[i+1]) && s[i+1] != '\0') ? -romValue(s[i]) : romValue(s[i]);
        }
        
        return sum;
    }
};
