class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> rows;
        vector<int> cols;

        // Step 1: find all positions of 0
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        // Step 2: make entire row 0
        for (int row : rows) {
            for (int j = 0; j < c; j++) {
                matrix[row][j] = 0;
            }
        }

        // Step 3: make entire column 0
        for (int col : cols) {
            for (int i = 0; i < r; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
