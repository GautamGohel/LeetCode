class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev2=1;
        int prev1=1;
        int steps;
        for(int i=2;i<=n;i++){
           steps=prev2+prev1;
           prev2=prev1;
           prev1=steps;
        }
        return steps;
    }
};