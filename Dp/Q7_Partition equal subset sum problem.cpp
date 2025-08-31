Partition equal subset sum problem
TOP DOWN APPROACH
class Solution {
  public:
    vector<vector<int>> dp; 
    // dp[i][t] = -1 (not computed), 0 (false), 1 (true)

    bool helper(vector<int>& nums, int n, int target) {
        // Base cases
        if (target == 0) return true;
        if (n == 0) return false;

        // If already computed
        if (dp[n][target] != -1) return dp[n][target];

        if (nums[n-1] > target) {
            return dp[n][target] = helper(nums, n-1, target);
        }

        // Choice: exclude or include
        bool exclude = helper(nums, n-1, target);
        bool include = helper(nums, n-1, target - nums[n-1]);

        return dp[n][target] = (exclude || include);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;  // odd sum not possible

        int target = total / 2;
        dp.assign(n+1, vector<int>(target+1, -1)); // initialize memo

        return helper(nums, n, target);
    }
};
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  BOTTOM APPROACH || Tabulation Approach
class Solution {
  public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        // If total sum is odd, cannot partition equally
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // Fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }

        return dp[n][target];
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------------
\\Space Optimized Dp(1D)
  class Solution {
  public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;  // sum 0 is always possible

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

