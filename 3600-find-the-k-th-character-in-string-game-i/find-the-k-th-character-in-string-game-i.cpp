class Solution {
public:
    char nextChar(char c) {
        return (c == 'z') ? 'a' : (c + 1);
    }

    char findChar(int k, int len, char base) {

        if (len == 1) return base;

        int half = len / 2;
        if (k <= half) {
            return findChar(k, half, base);
        } else {
            char prev = findChar(k - half, half, base);
            return nextChar(prev);
        }
    }

    char kthCharacter(int k) {
        int len = 1;
        while (len < k) len *= 2;  // find length just >= k

        return findChar(k, len, 'a');
    }
};
