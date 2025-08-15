class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check positive, power of two, and only odd bit set
        return n > 0 &&
            (n & (n - 1)) == 0 &&   // power of two
            (n & 0x55555555);       // bit in odd position
    }

};