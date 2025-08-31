\\count of subset sum with given sum
\\ Top down Approach
class Solution {
  public:
    vector<vector<int>> dp; // dp[i][t] = number of subsets using first i items to form t

    int helper(vector<int>& arr, int n, int target) {
        // Base cases
        if (target == 0) return 1;   // Empty subset is 1 valid way
        if (n == 0) return 0;       // No items left but target > 0 → no way

        // Already computed
        if (dp[n][target] != -1) return dp[n][target];

        if (arr[n-1] > target) {
            // Can't take this element
            return dp[n][target] = helper(arr, n-1, target);
        }

        // Choice: exclude OR include
        int exclude = helper(arr, n-1, target);
        int include = helper(arr, n-1, target - arr[n-1]);

        return dp[n][target] = exclude + include;
    }

    int countSubsets(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.assign(n+1, vector<int>(sum+1, -1));
        return helper(arr, n, sum);
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------
  Bottm Up Approach
  int countSubsets(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    // Base case: dp[i][0] = 1 (empty subset)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

