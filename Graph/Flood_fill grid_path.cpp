BY BFS-----------------------------------------------------------------------------------------------------------------
  #include <vector>
#include <queue>
#include <utility> 

using namespace std;

class Solution {
private:
    // Direction arrays for the four neighbors (up, right, down, left)
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int r, c; // Variables for image dimensions (rows and columns)

    // BFS implementation for the Flood Fill operation
    void bfs(int sr, int sc, int org_color, int color, vector<vector<int>>& image) {
        
        // If the color is already the target color, no need to proceed
        if (org_color == color) {
            return;
        }

        // Queue to store coordinates (row, column) of cells to be processed
        queue<pair<int, int>> q;
        
        // Start the BFS from the source cell
        q.push({sr, sc});
        
        // Change the starting cell's color immediately
        image[sr][sc] = color;

        // Process cells until the queue is empty
        while (!q.empty()) {
            
            // Get the front element and remove it (FIFO)
            pair<int, int> f = q.front();
            q.pop(); 

            int i = f.first;
            int j = f.second;

            // Explore the four neighbors
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                // Check for valid boundaries and the original color
                // If out of bounds or the color is not the original color, skip
                if (ii < 0 || jj < 0 || ii >= r || jj >= c || image[ii][jj] != org_color) {
                    continue;
                }
                
                // Add the valid neighbor to the queue
                q.push({ii, jj});
                
                // Change its color to mark it as visited and filled
                image[ii][jj] = color;
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Get image dimensions
        r = image.size();
        c = image[0].size();
        
        // Save the original color of the starting pixel
        int org_color = image[sr][sc];

        // Start the BFS
        bfs(sr, sc, org_color, color, image);
        
        // Return the modified image
        return image;
    }
};


BY DFS -------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int r, c;

    void dfs(int i, int j, int org_color, int color, vector<vector<int>>& image) {
        if (i < 0 || j < 0 || i >= r || j >= c || image[i][j] != org_color) {
            return;
        }

        image[i][j] = color;

        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(ii, jj, org_color, color, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();
        int org_color = image[sr][sc];

        if (org_color == color) return image;

        dfs(sr, sc, org_color, color, image);
        return image;
    }
};

  
