class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
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
};
