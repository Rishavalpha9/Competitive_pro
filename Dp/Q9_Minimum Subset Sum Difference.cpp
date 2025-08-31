\\Minimum Subset Sum Difference
class Solution {
  public:
    vector<vector<int>> dp;  // memo table

    int helper(vector<int>& arr, int n, int sumCalculated, int total) {
        // Base case
        if (n == 0) {
            return abs((total - sumCalculated) - sumCalculated);
        }

        // Already computed?
        if (dp[n][sumCalculated] != -1)
            return dp[n][sumCalculated];

        // Choice 1: include current element in subset sumCalculated
        int include = helper(arr, n-1, sumCalculated + arr[n-1], total);

        // Choice 2: exclude current element
        int exclude = helper(arr, n-1, sumCalculated, total);

        // Take min of both
        return dp[n][sumCalculated] = min(include, exclude);
    }

    int minSubsetSumDifference(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        // dp[n+1][total+1]
        dp.assign(n+1, vector<int>(total+1, -1));

        return helper(arr, n, 0, total);
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------
  BOTTOM UP APPROACH
  class Solution {
  public:
    int minSubsetSumDifference(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        int target = total / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // Base case
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // Fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // Find the closest sum to total/2
        int best = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[n][j]) {
                best = j;
                break;
            }
        }

        return total - 2*best;
    }
};

