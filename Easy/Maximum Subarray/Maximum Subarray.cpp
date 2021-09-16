//Link to the puzzle: https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0]; //curSum is 0 (start value to start adding numbers), maxSum is nums[0] (to initialize the sum's base value);
        
        //For each number in array:
        for (int i = 0; i < nums.size(); ++i) {
            if (curSum < 0) //If curSum is 0, initialize it with 0 (we are searching for MAX sum, not negative or 0);
                curSum = 0;
            
            curSum += nums[i]; //Add cur num to curSum and update maxSum if necessary;
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};
