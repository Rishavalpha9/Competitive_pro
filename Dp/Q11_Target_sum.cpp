
P = elements with + sign
N = elements with - sign
  P−N=S
P+N=totalSum
  2P=totalSum+S
  P=(totalSum+S​)/2
  This reduces the problem to count subsets with sum = (total + target)/2.

TOP DOWM APPROACH
class Solution {
public:
    vector<vector<int>> dp;

    int countSubsets(vector<int>& arr, int n, int sum) {
        // Base Cases
        if (sum == 0) return 1;   // one valid subset (empty set)
        if (n == 0) return 0;

        // Memoization check
        if (dp[n][sum] != -1) return dp[n][sum];

        if (arr[n-1] <= sum) {
            int include = countSubsets(arr, n-1, sum - arr[n-1]);
            int exclude = countSubsets(arr, n-1, sum);
            return dp[n][sum] = include + exclude;
        } else {
            return dp[n][sum] = countSubsets(arr, n-1, sum);
        }
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        int total = 0;
        for (int x : arr) total += x;

        // If total+target is odd or invalid
        if ((total + target) % 2 != 0 || target > total) return 0;

        int P = (total + target) / 2;

        int n = arr.size();
        dp.assign(n+1, vector<int>(P+1, -1));

        return countSubsets(arr, n, P);
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------------------
  BOTTOM UP  APPROACH
  class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int total = 0;
        for (int x : arr) total += x;

        if ((total + target) % 2 != 0 || abs(target) > total) return 0;

        int P = (total + target) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n+1, vector<int>(P+1, 0));

        // Base case: one way to make sum 0 (empty set)
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= P; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][P];
    }
};
