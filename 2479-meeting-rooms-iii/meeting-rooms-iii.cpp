#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        
        vector<int> roomUsageCount(n, 0);
        
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            
            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                busyRooms.push({end, room});
                roomUsageCount[room]++;
            } else {
                auto [freeTime, room] = busyRooms.top();
                busyRooms.pop();
                long long newEnd = freeTime + (end - start);
                busyRooms.push({newEnd, room});
                roomUsageCount[room]++;
            }
        }
        
        int maxMeetings = 0;
        int mostUsedRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsageCount[i] > maxMeetings) {
                maxMeetings = roomUsageCount[i];
                mostUsedRoom = i;
            }
        }
        
        return mostUsedRoom;
    }
};
