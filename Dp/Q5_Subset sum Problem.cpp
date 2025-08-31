//Top Down Approach
class Solution {
  public:
    // dp[i][j] = -1 → not computed
    // dp[i][j] = 0  → false
    // dp[i][j] = 1  → true
    vector<vector<int>> dp;

    bool helper(vector<int>& arr, int n, int sum) {
        // Base cases
        if (sum == 0) return true;
        if (n == 0) return false;

        // If already computed, return it
        if (dp[n][sum] != -1) 
            return dp[n][sum];

        if (arr[n-1] > sum) {
            // Can't include current element
            return dp[n][sum] = helper(arr, n-1, sum);
        } else {
            // Exclude OR include
            bool exclude = helper(arr, n-1, sum);
            bool include = helper(arr, n-1, sum - arr[n-1]);
            return dp[n][sum] = (exclude || include);
        }
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.assign(n+1, vector<int>(sum+1, -1));  // initialize memo table
        return helper(arr, n, sum);
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bottom Up approach
  class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        // Base case: sum = 0 is always true
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];   // can't include current
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }

        return dp[n][sum];
    }
};
