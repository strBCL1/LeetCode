//Link to the puzzle: https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1; //Add 1 to last digit;
        int i = digits.size() - 1; //Initialize index to traverse all digits in array from least significant digit;
		
		//While last digit is greater than 9 (10):
        while (digits[i] >= 10) {
            digits[i] = 0; //Initialize current digit with 0 (10 --> 0);
			if (i - 1 >= 0) //If current digit isn't very left - add 1 to it;
				digits[i-- -1] += 1;
			else // Else if current digit is very left: insert 1 into the beginning of array; 
				digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
