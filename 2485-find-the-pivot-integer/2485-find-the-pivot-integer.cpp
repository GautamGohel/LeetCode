class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return n;

        vector<int> v;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            v.push_back(1 + i);
        }

        std::vector<int> res;

        for (int i = 0; i < n; i++) {
            sum += v[i];
            res.push_back(sum);
        }

        int totalSum = sum; 
        sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum == totalSum - sum - v[i]) {
                return i + 1; 
            }
            sum += v[i];
        }

        return -1;  
    }
};