class Solution {
public:
    int minBitFlips(int start, int goal) {

        int xr = start ^ goal;
        int ans = 0;
        while (xr > 0) {
            ans += xr & 1; 
            xr >>= 1;
        }
        
        return ans;
    }
};