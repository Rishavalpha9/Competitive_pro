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

