/*          In 0/1 Knapsack, once you decide on an item, you cannot take it again.

            In Unbounded Knapsack, you can include the same item multiple times.               *\

  TOP DOWM APPROACH (Recursion and Memorixation)
  class Solution {
public:
    vector<vector<int>> dp;

    int helper(vector<int>& wt, vector<int>& val, int n, int W) {
        // Base case
        if (n == 0 || W == 0) return 0;

        if (dp[n][W] != -1) return dp[n][W];

        if (wt[n-1] <= W) {
            // Option 1: Take the item (and stay at same index, since unlimited supply)
            int include = val[n-1] + helper(wt, val, n, W - wt[n-1]);

            // Option 2: Skip the item
            int exclude = helper(wt, val, n-1, W);

            return dp[n][W] = max(include, exclude);
        } else {
            return dp[n][W] = helper(wt, val, n-1, W);
        }
    }

    int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        dp.assign(n+1, vector<int>(W+1, -1));
        return helper(wt, val, n, W);
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------
  BOTTOM UP APPROACH
  class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        // Build table
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    // Option 1: include item (stay at same i)
                    dp[i][w] = max(val[i-1] + dp[i][w - wt[i-1]], dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------
 Constant Space optimized
  class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> dp(W+1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = wt[i]; w <= W; w++) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};
