class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;

        vector<pair<int, int>> v(total + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[mat[i][j]] = {i, j};
            }
        }

        vector<int> hashrow(m, n);
        vector<int> hashcol(n, m);

        for (int i = 0; i < total; i++) {
            int row = v[arr[i]].first;
            int col = v[arr[i]].second;

            hashrow[row]--;
            hashcol[col]--;

            if (hashrow[row] == 0 || hashcol[col] == 0) {
                return i;
            }
        }

        return -1;
    }
};
