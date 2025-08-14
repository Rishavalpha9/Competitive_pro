70. Climbing Stairs
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
BOTTOM UP APPROACH
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;  // base cases

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOP DOWN APPROACH
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n <= 2) return n;  // Base cases: 1 -> 1 way, 2 -> 2 ways
        if (dp[n] != -1) return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Space-Optimized Version (O(1) space)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

