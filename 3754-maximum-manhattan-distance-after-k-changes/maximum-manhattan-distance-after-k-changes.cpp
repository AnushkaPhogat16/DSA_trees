class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int north = 0, south = 0, east = 0, west = 0;
        int maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'N') north++;
            else if (s[i] == 'S') south++;
            else if (s[i] == 'E') east++;
            else if (s[i] == 'W') west++;

            int vertical = abs(north - south);
            int horizontal = abs(east - west);
            int rawDist = vertical + horizontal;

            // You can make at most k changes to improve the distance
            // Each change can improve by 2 units (at most)
            int improvedDist = min(i + 1, rawDist + 2 * k);
            maxDist = max(maxDist, improvedDist);
        }

        return maxDist;
    }
};
