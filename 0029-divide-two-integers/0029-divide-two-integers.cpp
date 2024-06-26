class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX; // handle division by zero
        if (dividend == 0) return 0;
        
        long ans = 0;
        long n = labs(dividend); // use labs for absolute value of long
        long d = labs(divisor);
        bool sign = (dividend > 0) ^ (divisor > 0); // true if signs are different
        
        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            ans += multiple;
        }
        
        if (sign) ans = -ans;
        
        // Handle overflow
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        
        return (int)ans;
    }
};
