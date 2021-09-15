//Link to the puzzle: https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, const int& target) {
        if (target < nums[0]) //If target is smaller than very first number, return 0;
            return 0;
        
        if (target > nums.back()) //If target is greater than very end number, return nums.size();
            return nums.size();
        
        //Perform binary search to find the insert position or the occurence of target in array;
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int midIndex = left + (right - left) / 2; //Avoid buffer-overflow;
            
            if (nums[midIndex] == target)
                return midIndex;
            
            else if (nums[midIndex] < target)
                left = midIndex + 1;
            
            else if (nums[midIndex] > target)
                right = midIndex - 1;
        }
        
        return left;
    }
};
