// Count subsets with sum = (diff + total) / 2
Top down Appraoch


class Solution {
  public:
    vector<vector<int>> dp;

    int countSubsets(vector<int>& arr, int n, int target) {
        if (target == 0) return 1;   // one valid subset (empty subset if allowed)
        if (n == 0) return 0;

        if (dp[n][target] != -1) return dp[n][target];

        if (arr[n-1] <= target) {
            // include or exclude
            return dp[n][target] = countSubsets(arr, n-1, target - arr[n-1]) 
                                 + countSubsets(arr, n-1, target);
        } else {
            // can't include
            return dp[n][target] = countSubsets(arr, n-1, target);
        }
    }

    int countPartitions(vector<int>& arr, int diff) {
        int total = 0;
        for (int x : arr) total += x;

        // If (total + diff) is odd, no solution
        if ((total + diff) % 2 != 0 || diff > total) return 0;

        int target = (total + diff) / 2;

        dp.assign(arr.size() + 1, vector<int>(target + 1, -1));
        return countSubsets(arr, arr.size(), target);
    }
};
------------------------------------------------------------------------------------------------------------------------------------------------------------
  Bottom Up Approach
  class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int total = 0;
        for (int x : arr) total += x;

        // If (total + diff) is odd or diff > total, no solution
        if ((total + diff) % 2 != 0 || diff > total) return 0;

        int target = (total + diff) / 2;
        int n = arr.size();

        // dp[i][j] = count of subsets from first i elements with sum j
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // Base case: sum = 0 → 1 way (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------
  Constant space 
  class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int total = 0;
        for (int x : arr) total += x;

        if ((total + diff) % 2 != 0 || diff > total) return 0;
        int target = (total + diff) / 2;

        vector<int> dp(target+1, 0);
        dp[0] = 1;  // one way to make sum=0

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[target];
    }
};
