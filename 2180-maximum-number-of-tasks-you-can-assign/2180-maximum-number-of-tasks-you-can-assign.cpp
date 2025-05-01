class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end()); // weak task first
        sort(workers.rbegin(), workers.rend()); // strongest person first;

        int ans = 0;

        int l = 0;
        int h = tasks.size();

        auto possible = [](vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
            if(workers.size() < k) return false;

            multiset<int> ms(workers.begin(), workers.begin() + k);

            auto it = prev(ms.end());

            k--;
            while(k >= 0) {
                int currentTask = tasks[k];

                if(currentTask > *it) {
                    if(!pills) return false;
                    // pill is required
                    // give pill to weakest worker;
                    auto lb = ms.lower_bound(currentTask - strength);
                    if(lb == ms.end()) return false;
                    if(lb != it) {
                        ms.erase(lb);
                        k--;
                        pills--;
                        continue;
                    }
                }  

                auto preIt = it;
                it--;
                ms.erase(preIt);
                k--;
            }

            return true;
        };

        while(l <= h) {
            int mid = (l + h) / 2;

            if(possible(tasks, workers, pills, strength, mid)) {
                ans = mid;
                l = mid + 1;
            } else h = mid - 1;
        }

        return ans;
    }
};