class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(m * n * (m + n))
    // Check every server and determine if it can communicate with another by traversing its entire row and column.
    bool canCommunicate(int row, int col, vector<vector<int>>& grid, int rows, int cols) {
        for (int j = 0; j < cols; j++) {
            if (grid[row][j] == 1 && j != col) {
                return true;
            }
        }
        for (int i = 0; i < rows; i++) {
            if (grid[i][col] == 1 && i != row) {
                return true;
            }
        }
        return false;
    }

    int countServersBrute(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && canCommunicate(i, j, grid, rows, cols)) {
                    count++;
                }
            }
        }

        return count;
    }

    // Better Approach
    // Time Complexity: O(m * n)
    // First, count the number of servers in each row and column, then iterate again to determine if a server can communicate.
    int countServersBetter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowServerCount(rows, 0);
        vector<int> colServerCount(cols, 0);

        // Count the number of servers in each row and column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    rowServerCount[i]++;
                    colServerCount[j]++;
                }
            }
        }

        int count = 0;

        // Check if a server can communicate
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && (rowServerCount[i] > 1 || colServerCount[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }

    // Best Approach
    // Time Complexity: O(m * n)
    // Optimized to reduce unnecessary checks for rows with single servers by storing their column index.
    int countServersBest(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalServers = 0;

        vector<int> singleServerColumn(rows, -1); // Stores the column index of a single server in a row
        vector<int> columnServerCount(cols, 0);  // Counts the number of servers in each column

        // Traverse rows to calculate columnServerCount and identify rows with a single server
        for (int row = 0; row < rows; row++) {
            int rowServerCount = 0;
            int lastServerColumn = -1;

            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    rowServerCount++;
                    columnServerCount[col]++;
                    lastServerColumn = col;
                }
            }

            if (rowServerCount > 1) {
                totalServers += rowServerCount;
                singleServerColumn[row] = -1; // Reset since this row has multiple servers
            } else {
                singleServerColumn[row] = lastServerColumn; // Store the column index for a single server row
            }
        }

        // Check if any single server row's column has multiple servers
        for (int row = 0; row < rows; row++) {
            if (singleServerColumn[row] != -1) {
                int col = singleServerColumn[row];
                if (columnServerCount[col] > 1) {
                    totalServers++;
                }
            }
        }

        return totalServers;
    }

    // Wrapper function to call all three approaches
    int countServers(vector<vector<int>>& grid) {
        // Uncomment the desired approach to use:
        // return countServersBrute(grid);   // Brute Force Approach
        // return countServersBetter(grid); // Better Approach
        return countServersBest(grid);      // Best Approach
    }
};
