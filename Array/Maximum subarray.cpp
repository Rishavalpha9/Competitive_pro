kadans Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = INT_MIN;
        for (int val : nums) {
            currsum += val;
            maxsum = max(currsum, maxsum);
            if (currsum < 0) {
                currsum = 0;
            }
        }
        return maxsum;
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  DP
  class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int i) {
        if (i == 0) return nums[0]; // base case
        if (dp[i] != INT_MIN) return dp[i];

        // Either start new subarray from nums[i] or extend previous
        dp[i] = max(nums[i], nums[i] + solve(nums, i - 1));
        return dp[i];
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, INT_MIN);

        int ans = nums[0];
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, i));
        }
        return ans;
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
