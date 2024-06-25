class Solution {
public:
    int minBitFlips(int start, int goal) {
        start=start^goal;
        int cnt=0;
        while(start){
           cnt+=(start&1);
           start=start>>1;
        }
        return cnt;
    }
};