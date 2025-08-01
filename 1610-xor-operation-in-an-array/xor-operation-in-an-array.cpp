class Solution {
public:
    int xorX(int a){
        if(a % 4 == 0) return a;
        else if(a % 4 == 1) return 1;
        else if(a % 4 == 2) return a + 1;
        else return 0;
    }

    int xorOperation(int n, int start) {
        int s = start >> 1;        
        int xorS = xorX(s + n - 1);
        if (s > 0) xorS ^= xorX(s - 1);
        return (xorS << 1) | (n & start & 1);
    }    
};
