class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        set<int> availableDays;
        for (int day = 1; day <= 100000; ++day) {
            availableDays.insert(day);
        }

        int attended = 0;

        for (auto& event : events) {
            int start = event[0], end = event[1];

            auto it = availableDays.lower_bound(start);
            if (it != availableDays.end() && *it <= end) {
                attended++;
                availableDays.erase(it);  // Mark day as taken
            }
        }

        return attended;
    }
};
