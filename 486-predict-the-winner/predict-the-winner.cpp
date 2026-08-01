class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
    int solve(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i];                
        int pickLeft  = nums[i] - solve(nums, i+1, j);
        int pickRight = nums[j] - solve(nums, i, j-1);
        return max(pickLeft, pickRight);           
    }
};