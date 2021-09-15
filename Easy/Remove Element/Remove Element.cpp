class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
      
        //Remove all occurences of 'val' in array;
        nums.erase(remove(begin(nums), end(nums), val), end(nums));
        
        return nums.size();
    }
};
