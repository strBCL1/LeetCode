//Link to the puzzle: https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, const int& target) {
        unordered_map<int, int> m; //Number in 'numbers' <-> its index;
        
        //For each number in 'numbers':
        for (int i = 0; i < numbers.size(); ++i) {
            auto findDifference = m.find(target - numbers[i]);
            
              //If the difference of target sum and current number is present as a key in map, return indices: {index of cur number in array, index of found difference};
            if (findDifference != m.end()) {
                return {i, findDifference->second};
            }
            
            //Else create pair of current number and its index;
            else {
                m[numbers[i]] = i;
            }
        }
        
        //If nothing was found - return pairs of 0 indices {0, 0};
        return {0, 0};
    }
};
