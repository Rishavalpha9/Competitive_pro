class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        result.push_back({1});               // row 1
        if (numRows == 1) return result;

        result.push_back({1, 1});            // row 2
        if (numRows == 2) return result;

        for (int i = 2; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);

            // if even-length row
            if ((i + 1) % 2 == 0) {
                for (int p = 1; p < (i + 1) / 2; p++) {
                    row.push_back(result[i - 1][p - 1] + result[i - 1][p]);
                }
                for (int p = (i + 1) / 2; p < i; p++) {
                    row.push_back(row[i - p]);
                }
            } 
            // if odd-length row
            else {
                for (int p = 1; p <= i / 2; p++) {
                    row.push_back(result[i - 1][p - 1] + result[i - 1][p]);
                }
                for (int p = i / 2 + 1; p < i; p++) {
                    row.push_back(row[i - p]);
                }
            }

            row.push_back(1);
            result.push_back(row);
        }

        return result;
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  More Optimized
  class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        // Base case: first row
        res.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // initialize row with 1s
            for (int j = 1; j < i; j++) {
                // each element is sum of two elements above it
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }

        return res;
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  By Dp(Top Down)
  class Solution {
public:
    vector<vector<int>> dp; // memo table

    // Recursive function with memoization
    int getValue(int n, int r) {
        if (r == 0 || r == n) return 1; // first and last element = 1

        if (dp[n][r] != -1) return dp[n][r]; // already computed

        return dp[n][r] = getValue(n - 1, r - 1) + getValue(n - 1, r);
    }

    vector<vector<int>> generate(int numRows) {
        dp.assign(numRows, vector<int>(numRows, -1)); // initialize memo table

        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(getValue(i, j));
            }
            result.push_back(row);
        }
        return result;
    }
};
