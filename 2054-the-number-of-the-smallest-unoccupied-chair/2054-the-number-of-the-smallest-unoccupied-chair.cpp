class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n  = times.size();

        // Set to keep track of available seats
        set<int> availableSeats;
        for(int i = 0; i < n; i++) {
            availableSeats.insert(i);
        }

        // Map to track which friend occupies which seat
        unordered_map<int, int> friendToSeat; // (friend, seat_number)
        
        // Separate vectors for arrival and departure times
        vector<pair<int, int>> arr;
        vector<pair<int, int>> dep;
        for(int i = 0; i < n; i++) {
            arr.push_back({times[i][0], i});
            dep.push_back({times[i][1], i});
        }
        
        // Sort arrivals by time, and departures by time 
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        // Simulate the arrival and departure process
        while(i < n && j < n) {
            int arrTime = arr[i].first;
            int depTime = dep[j].first;
            int frndArr = arr[i].second;
            int frndDep = dep[j].second;

            if(arrTime < depTime) { // Strictly less [SINCE, AT FIRST THE SEAT WILL GET VACANT]
                // Friend arrives and takes the smallest available seat
                auto it = availableSeats.begin();
                friendToSeat[frndArr] = *it;
                availableSeats.erase(it); // Seat is now occupied
                i++;
            } else {
                // Friend departs and vacates their seat
                int seatNumber = friendToSeat[frndDep];
                availableSeats.insert(seatNumber); // Seat is now available
                j++;
            }
        }
        return friendToSeat[targetFriend];
    }
};