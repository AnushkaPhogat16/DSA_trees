class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = sortDigits(n);
        
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30 (max fits in int)
            int power = 1 << i;
            if (sortDigits(power) == target) return true;
        }
        
        return false;
    }
    
private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};
