class Solution {
public:
    int findClosest(int x, int y, int z) {
        if((abs(x-z)) == (abs(z-y))) return 0;
        return ( (abs(x-z) < (abs(z-y)) ) ? 1 : 2  );
    }
};