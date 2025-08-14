House Robber 1
------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOP DOWN 
class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(nums, i + 2, n, dp); // rob this house
        int skip = solve(nums, i + 1, n, dp);           // skip this house

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);  // dp[i] stores max money starting from house i
        return solve(nums, 0, n, dp);
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
