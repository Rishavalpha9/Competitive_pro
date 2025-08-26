
Top down Approach
// Recursive function with memoization
int solve(int index, int capacity, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {
    // Base case: if we are at the first item
    if (index == 0) {
        if (weights[0] <= capacity) return values[0];
        return 0;
    }

    // If already computed, return stored value
    if (dp[index][capacity] != -1) return dp[index][capacity];

    // Option 1: Do not take this item
    int notTake = solve(index - 1, capacity, weights, values, dp);

    // Option 2: Take this item (only if it fits)
    int take = 0;
    if (weights[index] <= capacity) {
        take = values[index] + solve(index - 1, capacity - weights[index], weights, values, dp);
    }

    // Store and return the best of both choices
    return dp[index][capacity] = max(take, notTake);
}

int knapSack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create DP table and initialize with -1
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    // Start recursion from the last item
    return solve(n - 1, capacity, weights, values, dp);
}


------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Bottom Up Approach
  int knapSack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create a DP table: n rows (items) x (capacity+1) columns
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Base case: Fill first row (using only item 0)
    for (int w = weights[0]; w <= capacity; w++) {
        dp[0][w] = values[0];
    }

    // Fill the table row by row
    for (int i = 1; i < n; i++) {              // for each item
        for (int w = 0; w <= capacity; w++) {  // for each weight capacity
            int notTake = dp[i - 1][w];        // don't take this item
            int take = 0;
            if (weights[i] <= w) {             // take this item if it fits
                take = values[i] + dp[i - 1][w - weights[i]];
            }
            dp[i][w] = max(take, notTake);     // best of both
        }
    }

    return dp[n - 1][capacity]; // answer is in last cell
}
