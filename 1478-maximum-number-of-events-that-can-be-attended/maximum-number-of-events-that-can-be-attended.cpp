class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events based on their start times
        sort(events.begin(), events.end());
        
        int totalDays = 0;
        for (const auto& event : events) {
            // Find the maximum end day among all events
            totalDays = max(totalDays, event[1]);
        }
        
        // Min heap to track end times of ongoing events
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int currentDay = 1, attendedEvents = 0, eventIndex = 0;
        
        while (currentDay <= totalDays) {
            // If there are no ongoing events for the current day, move to the next available event
            if (eventIndex < events.size() && minHeap.empty()) {
                currentDay = events[eventIndex][0];
            }
            
            // Add newly available events to the min heap
            while (eventIndex < events.size() && events[eventIndex][0] <= currentDay) {
                minHeap.push(events[eventIndex][1]);
                eventIndex++;
            }
            
            // Remove events from the heap that have already ended
            while (!minHeap.empty() && minHeap.top() < currentDay) {
                minHeap.pop();
            }
            
            // Attend the event that ends the earliest among ongoing events
            if (!minHeap.empty()) {
                minHeap.pop();
                attendedEvents++;
            } else if (eventIndex >= events.size()) {
                // No more events to attend, so stop early
                break;
            }
            
            currentDay++;
        }
        
        return attendedEvents;
    }
};