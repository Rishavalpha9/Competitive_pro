213. House Robber II
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
// TOP DOWM  
  class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>& dp) {

        if (i > n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int take = nums[i] + solve(nums,i+2,n, dp);
        int skip = solve(nums,i+1, n, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(101, -1);
        // if we roob in 1st house.
        int taken_1st_house = solve(nums, 0, n - 2, dp);
        vector<int> dp1(101, -1);
        // if we roob 2nd house in circular order.
        int taken_2nd_house = solve(nums, 1, n - 1, dp1);

        return max(taken_1st_house, taken_2nd_house);
    }
};
------------------------------------------------------------------------------------------------------------------------------------------------------------------
// BOTTOM UP 
  class Solution {
public:
    int n;

    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> t(n + 1, 0);
        // t[i] = Max money gained from i houses

        int result1 = 0;
        int result2 = 0;

        // Case-1 (Take from 1st House - Hence skip the last house)
        t[0] = 0;
        for (int i = 1; i <= n - 1; i++) {
            int skip = t[i - 1];
            int take = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);

            t[i] = max(skip, take);
        }
        result1 = t[n - 1];

        t.clear();
        // Case-2 (Take from 2nd House - Hence take the last house)
        t[0] = 0;
        t[1] = 0;
        for (int i = 2; i <= n; i++) {
            int skip = t[i - 1];
            int take = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);

            t[i] = max(skip, take);
        }
        result2 = t[n];

        return max(result1, result2);
    }
};
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  


