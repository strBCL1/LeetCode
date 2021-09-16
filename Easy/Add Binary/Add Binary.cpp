class Solution {
public:
    string answer = ""; //String to store the answer of puzzle;
    int carry = 0; //Carry - used in binary summation;
    int aIndex, bIndex; //Variables to iterate over 'a' and 'b' strings;

    //Pass 'a' and 'b' by reference to reduce disk space usage; 
    //Initialize 'a' and 'b' with 'const' keyword to pass them by rvalue;
    void getSum(const string& a, const string& b) {
        aIndex = a.size() - 1; //Initialize aIndex with last 'a' digit index;
        bIndex = b.size() - 1; //Initialize bIndex with last 'b' digit index;

        //While either 'aIndex' or 'bIndex' hasn't reached the leftmost position, perform summation:
        for (; aIndex >= 0 || bIndex >= 0; --aIndex, --bIndex) {
            int digitsSum = 0;
            if (aIndex >= 0) //If 'aIndex' hasn't reached out of scope --> add its digit to digitsSum;
                digitsSum += a[aIndex]-'0';
            
            if (bIndex >= 0) //If 'BIndex' hasn't reached out of scope --> add its digit to digitsSum;
                digitsSum += b[bIndex]-'0';
            
            digitsSum += carry; //Add carry to digitsSum;
            carry = digitsSum / 2; //If digitsSum is 2 or 3 --> carry will ALWAYS be 1, else 0;

            answer += (digitsSum % 2) + '0'; //If digitsSum is even, add '0' to answer, else '1';
        }

        if (carry != 0) //If carry is left, add it to answer;
            answer += '1';
    }

    string addBinary(const string& a, const string& b) {
        if (!a.empty() && !b.empty()) //If both 'a' and 'b' aren't empty - add them;
            getSum(a, b);
        
        if (aIndex > 0) //If 'a' is longer than 'b', e.g. "10111" and "11" --> add "101" to total sum;
            getSum(a, "");

        else if (bIndex > 0) //Else if 'b' is longer than 'a', e.g. "11" and "10111" --> add "101" to total sum;
            getSum("", b);

        //Return reversed string using 'string' constructor and iterators;
        return string(answer.rbegin(), answer.rend());
    }
};
